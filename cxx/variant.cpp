#include "magdle.h"
#include "variant.h"
#include <c++/9/cstring>

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

    int len = o.length();
    alloc(len);
    if (len) {
        memcpy(_raw, o.buf(), len);
    }
}

Variant::~Variant() {
    clear();
}

Variant &Variant::refto(void *ptr, size_t s) {
    clear();
    _owner = false;
    _raw = ptr;
    _length = s;
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
