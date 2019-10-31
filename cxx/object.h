#ifndef _ME_OBJECT_H
#define _ME_OBJECT_H

ME_NAMESPACE_BEGIN

class Variant;

class BinaryOutput {
public:

    template<typename T>
    inline BinaryOutput &operator<<(T const &v) {
        _out << sizeof(v);
        _out << v;
        return *this;
    }

    BinaryOutput &write(void const *ptr, size_t s) {
        if (s == 0 || ptr == nullptr) {
            _out << s;
        } else {
            _out << s;
            _out.write((char const *) ptr, s);
        }
        return *this;
    }

    // 复制当前内容到Variant对象
    void copyto(Variant &);

private:
    ostringstream _out;
};

class BinaryInput {
public:

    BinaryInput(void const *ptr, size_t s);

    explicit BinaryInput(Variant const &);

    template<typename T>
    inline BinaryInput &operator>>(T &v) {
        size_t s;
        _in >> s;
        if (s != sizeof(v))
            throw "类型不匹配";
        _in >> v;
        return *this;
    }

    // 读取，重新分配variant的内存
    BinaryInput &read(Variant &);

    // 将制定长度的数据copy到对应位置，如果大小不同则抛出异常
    BinaryInput &copyto(void *buf, size_t len);

private:
    istringstream _in;
};

interface ISerialableObject {

    // 输出
    virtual bool serialize(BinaryOutput &) const = 0;

    // 读入
    virtual bool unserialize(BinaryInput &) = 0;
};

ME_NAMESPACE_END

#endif
