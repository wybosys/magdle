#include "magdle.h"
#include "variant.h"
#include <c++/9/cstring>

ME_NAMESPACE_BEGIN

Variant::Variant(int v)
        : type(VariantType::INTEGER),
          length(sizeof(long)) {
    raw = malloc(length);
    (*(long *) raw) = v;
}

Variant::Variant(std::string const &str)
        : type(VariantType::STRING),
          length(str.length()) {
    raw = malloc(length);
    memcpy(raw, str.c_str(), length);
}

Variant::~Variant() {
    free(raw);
    raw = nullptr;
}

ME_NAMESPACE_END
