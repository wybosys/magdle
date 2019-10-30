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
public:

    Variant(int);
    Variant(string const&);
    ~Variant();

    // 当前数据类型
    VariantType const type = VariantType::UNKNOWN;

    // 字长
    size_t const length = 0;

    // 数据
    inline bytes const buffer() const {
        return (bytes const) raw;
    }

private:
    void *raw = nullptr;
};

ME_NAMESPACE_END

#endif
