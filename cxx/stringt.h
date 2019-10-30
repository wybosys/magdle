#ifndef _ME_STRINGT_H
#define _ME_STRINGT_H

ME_NAMESPACE_BEGIN

class stringbuilder {
public:
    template<typename T>
    inline stringbuilder &operator<<(T const &v) {
        _oss << v;
        _changed = true;
        return *this;
    }

    inline operator string const &() const {
        if (_changed) {
            _str = _oss.str();
            _changed = false;
        }
        return _str;
    }

    inline operator char const *() const {
        return ((string const &) (*this)).c_str();
    }

    inline size_t length() const {
        return ((string const &) (*this)).length();
    }

private:
    mutable bool _changed = false;
    mutable string _str;
    ostringstream _oss;
};

struct StringT {

    inline static string ToLowerCase(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

ME_NAMESPACE_END

#endif

