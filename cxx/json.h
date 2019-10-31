#ifndef _ME_JSON_H
#define _ME_JSON_H

#include <jsoncpp/json/json.h>

ME_NAMESPACE_BEGIN

typedef Json::Value json_type;

class JsonObj {
public:

    JsonObj() {}

    template<typename T>
    JsonObj(T const &r):_v(r) {}

    template<typename K, typename V>
    inline JsonObj &operator()(K const &k, V const &v) {
        return set(k, v);
    }

    template<typename K, typename V>
    inline JsonObj &set(K const &k, V const &v) {
        _v[k] = v;
        return *this;
    }

    inline operator json_type &() {
        return _v;
    }

    inline operator json_type const &() const {
        return _v;
    }

private:
    Json::Value _v;
};

extern json_type ToJsonObj(string const &, json_type def = json_type());

extern string ToJson(json_type const &);

ME_NAMESPACE_END

#endif

