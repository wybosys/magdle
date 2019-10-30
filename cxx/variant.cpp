#include "magdle.h"
#include "variant.h"
#include <c++/9/cstring>

ME_NAMESPACE_BEGIN

Variant::Variant() {
    // pass
}

Variant::Variant(int v)
        : type(VariantType::INTEGER),
          _length(sizeof(long)) {
    _raw = malloc(_length);
    (*(long *) _raw) = v;
}

Variant::Variant(string const &str)
        : type(VariantType::STRING),
          _length(str.length()) {
    _raw = malloc(_length);
    memcpy(_raw, str.c_str(), _length);
}

Variant::Variant(void const *p, size_t s) :
        _length(s) {
    _raw = malloc(_length);
    memcpy(_raw, p, _length);
}

Variant::Variant(char const *str)
        : type(VariantType::STRING),
          _length(strlen(str)) {
    _raw = malloc(_length);
    memcpy(_raw, str, _length);
}

Variant::~Variant() {
    free(_raw);
    _raw = nullptr;
}

ME_NAMESPACE_END
