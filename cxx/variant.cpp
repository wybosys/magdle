#include "magdle.h"
#include "variant.h"
#include CXX_INCLUDE(cstring)

ME_NAMESPACE_BEGIN

Variant::Variant() {
    // pass
}

Variant::Variant(int v)
        : _type(VariantType::INTEGER),
          _length(sizeof(long)) {
    _raw = malloc(_length);
    (*(long *) _raw) = v;
}

Variant::Variant(string const &str)
        : _type(VariantType::STRING),
          _length(str.length()) {
    _raw = malloc(_length);
    memcpy(_raw, str.c_str(), _length);
}

Variant::Variant(void const *p, size_t s, VariantType typ) :
        _length(s), _type(typ) {
    _raw = malloc(_length);
    if (p) {
        // p当填充数据时，会为null
        memcpy(_raw, p, _length);
    }
}

Variant::Variant(char const *str)
        : _type(VariantType::STRING),
          _length(strlen(str)) {
    _raw = malloc(_length);
    memcpy(_raw, str, _length);
}

Variant::Variant(JsonObj const &js)
        : _type(VariantType::JSON) {
    size_t &len = const_cast<size_t &>(_length);
    string str = ToJson(js);
    len = str.length();

    _raw = malloc(_length);
    memcpy(_raw, str.c_str(), _length);
}

Variant::Variant(ISerialableObject const &obj)
        : _type(VariantType::UNKNOWN) {
    BinaryOutput o;
    obj.serialize(o);
    o.copyto(*this);
}

Variant::~Variant() {
    clear();
}

Variant &Variant::refto(void const *ptr, size_t s) {
    clear();
    _owner = false;
    _raw = const_cast<void *>(ptr);
    _length = s;
    return *this;
}

Variant &Variant::copyfrom(void const *ptr, size_t s) {
    clear();
    alloc(s);
    if (s) {
        memcpy(_raw, ptr, s);
    }
    return *this;
}

Variant &Variant::alloc(size_t s) {
    clear();
    _length = s;

    if (s) {
        _raw = malloc(_length);
    }
    return *this;
}

ME_NAMESPACE_END
