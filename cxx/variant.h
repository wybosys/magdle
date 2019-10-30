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

    Variant(void const*, size_t);

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

private:
    void *_raw = nullptr;
    size_t const _length = 0;
};

ME_NAMESPACE_END

#endif
