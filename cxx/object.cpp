#include "magdle.h"
#include "object.h"

ME_NAMESPACE_BEGIN

void BinaryOutput::copyto(Variant &v) {
    string str = _out.str();
    v.copyfrom(str.c_str(), str.length());
}

BinaryOutput &BinaryOutput::write(Variant const &v) {
    size_t t = v.length();
    _out.write((char *) &t, sizeof(t));
    if (t) {
        _out.write(v, t);
    }
    return *this;
}

BinaryInput::BinaryInput(void const *ptr, size_t s) {
    _in.rdbuf()->pubsetbuf((char *) ptr, s);
}

BinaryInput::BinaryInput(Variant const &v) {
    _in.rdbuf()->pubsetbuf((char *) v.buffer(), v.length());
}

BinaryInput &BinaryInput::read(Variant &v) {
    size_t s;
    _in.read((char *) &s, sizeof(s));
    v.alloc(s);
    if (s != 0) {
        _in.read(v, s);
    }
    return *this;
}

BinaryInput &BinaryInput::copyto(void *buf, size_t len) {
    size_t s;
    _in.read((char *) &s, sizeof(s));
    if (len == 0 && s == 0)
        return *this;
    if (s != len)
        throw "输入的缓冲长度和当前待读取的长度不一致";
    _in.read((char *) buf, len);
    return *this;
}

ME_NAMESPACE_END
