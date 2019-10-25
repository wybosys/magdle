#ifndef _ME_STRINGT_H
#define _ME_STRINGT_H

ME_NAMESPACE_BEGIN

class stringbuilder
{
public:

    template <typename T>
    inline stringbuilder& operator << (T const& v) {
        _oss << v;
        return *this;
    }

    inline operator ::std::string() const {
        return _oss.str();
    }

private:
    ::std::ostringstream _oss;
};

struct StringT {

    inline static ::std::string ToLowerCase(::std::string str) {
        ::std::transform(str.begin(), str.end(), str.begin(), tolower);
        return str;
    }
};

ME_NAMESPACE_END

#endif

