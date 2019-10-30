#ifndef _ME_VARIANT_H
#define _ME_VARIANT_H

ME_NAMESPACE_BEGIN

enum struct VariantType {
    UNKNOWN = 0, // 未知类型
    INTEGER = 1, // 整数类型
    STRING = 2, // 字符串
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

    ~Variant();

    // 当前数据类型
    VariantType const type = VariantType::UNKNOWN;

    // 字长
    size_t const length() const {
        return _length;
    }

    // 数据
    inline bytes const buffer() const {
        return (bytes const) _raw;
    }

    inline operator int() const {
        return *(int *) _raw;
    }

    inline operator char const *() const {
        return (char const *) _raw;
    }

    inline operator string() const {
        return string((char const *) _raw, _length);
    }

    template<typename R>
    inline bool operator==(R const &v) const {
        return (R) (*this) == v;
    }

private:
    void *_raw = nullptr;
    size_t const _length = 0;
};

ME_NAMESPACE_END

#endif
