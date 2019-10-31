#ifndef _ME_VARIANT_H
#define _ME_VARIANT_H

#include "json.h"

ME_NAMESPACE_BEGIN

enum struct VariantType {
    UNKNOWN = 0, // 未知类型
    INTEGER = 1, // 整数类型
    STRING = 2, // 字符串
    JSON = 3, // json数据
};

// 负责承载不同类型数据的转换
class Variant {

    // 禁止copy
    Variant(Variant const &);

public:

    Variant();

    Variant(int);

    Variant(string const &);

    Variant(void const *, size_t, VariantType = VariantType::UNKNOWN);

    Variant(char const *);

    Variant(JsonObj const &);

    Variant(stringbuilder const &ss) : Variant(ss.string()) {}

    Variant(ISerialableObject const &);

    ~Variant();

    // 当前数据类型
    VariantType type() const {
        return _type;
    }

    // 字长
    size_t const length() const {
        return _length;
    }

    // 分配内存空间，分配后则丧失之前的数据类型和数据
    Variant &alloc(size_t);

    // 引用到对应缓存
    Variant &refto(void *ptr, size_t s);

    // 从原copy
    Variant &copyfrom(void const *ptr, size_t s);

    // 数据
    inline bytes const buffer() const {
        return (bytes const) _raw;
    }

    inline operator int() const {
        return *(int *) _raw;
    }

    inline operator char *() {
        return (char *) _raw;
    }

    inline operator char const *() const {
        return (char const *) _raw;
    }

    inline operator string() const {
        return string((char const *) _raw, _length);
    }

    inline operator JsonObj() const {
        return ToJsonObj((string) (*this));
    }

    template<typename R>
    inline bool operator==(R const &v) const {
        return (R) (*this) == v;
    }

protected:

    inline void clear() {
        if (_owner && _raw)
            free(_raw);
        _raw = nullptr;
        _length = 0;
        _owner = true;
        _type = VariantType::UNKNOWN;
    }

    bool _owner = true;
    void *_raw = nullptr;
    size_t _length = 0;
    VariantType _type = VariantType::UNKNOWN;
};

ME_NAMESPACE_END

#endif
