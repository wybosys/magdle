#ifndef _ME_STRINGT_H
#define _ME_STRINGT_H

ME_NAMESPACE_BEGIN

class stringbuilder {
public:
    explicit stringbuilder(string const &sep = "")
            : _sep(sep) {}

    template<typename T>
    inline stringbuilder &operator<<(T const &v) {
        _oss << v << _sep;
        _changed = true;
        return *this;
    }

    inline operator string const &() const {
        return string();
    }

    inline string const &string() const {
        if (_changed) {
            _str = _oss.str();
            _changed = false;
        }
        return _str;
    }

    inline operator char const *() const {
        return string().c_str();
    }

    inline size_t length() const {
        return string().length();
    }

    inline stringbuilder &clear() {
        _changed = true;
        _str = "";
        _oss.str("");
        return *this;
    }

private:
    mutable bool _changed = false;
    mutable ::std::string _str;
    ::std::string _sep;
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

