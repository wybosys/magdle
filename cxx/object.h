#ifndef _ME_OBJECT_H
#define _ME_OBJECT_H

ME_NAMESPACE_BEGIN

class Variant;

class BinaryOutput {
public:

    template<typename T>
    inline BinaryOutput &operator<<(T const &v) {
        size_t s = sizeof(v);
        _out.write((char *) &s, sizeof(s));
        _out.write((char *) &v, s);
        return *this;
    }

    template<>
    inline BinaryOutput &operator<<(Variant const &v) {
        return write(v);
    }

    BinaryOutput &write(Variant const &);

    BinaryOutput &write(void const *ptr, size_t s) {
        _out.write((char *) &s, sizeof(s));
        if (s == 0 || ptr == nullptr) {
            // pass
        } else {
            _out.write((char const *) ptr, s);
        }
        return *this;
    }

    // 复制当前内容到Variant对象
    void copyto(Variant &);

private:
    ostringstream _out = ostringstream(ios_base::binary);
};

class BinaryInput {
public:

    BinaryInput(void const *ptr, size_t s);

    explicit BinaryInput(Variant const &);

    template<typename T>
    inline BinaryInput &operator>>(T &v) {
        size_t s;
        _in.read((char *) &s, sizeof(s));
        if (s != sizeof(v))
            throw "类型不匹配";
        _in.read((char *) &v, s);
        return *this;
    }

    template<>
    inline BinaryInput &operator>>(Variant &v) {
        return read(v);
    }

    // 读取，重新分配variant的内存
    BinaryInput &read(Variant &);

    // 将制定长度的数据copy到对应位置，如果大小不同则抛出异常
    BinaryInput &copyto(void *buf, size_t len);

private:
    istringstream _in = istringstream(ios_base::binary);
};

interface ISerialableObject {

    // 输出
    virtual bool serialize(BinaryOutput &) const = 0;

    // 读入
    virtual bool unserialize(BinaryInput &) = 0;
};

ME_NAMESPACE_END

#endif
