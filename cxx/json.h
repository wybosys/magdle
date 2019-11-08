#ifndef _ME_JSON_H
#define _ME_JSON_H

#include <json/json.h>
#include "variant.h"

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

    template<typename K>
    inline json_type const &operator[](K const &k) const {
        return _v[k];
    }

    template<typename K>
    inline json_type &operator[](K const &k) {
        return _v[k];
    }

    template<typename K, typename V>
    inline JsonObj &set(K const &k, V const &v) {
        _v[k] = v;
        return *this;
    }

    template<typename K>
    inline json_type &get(K const &k) {
        return _v[k];
    }

    template<typename K>
    inline json_type const &get(K const &k) const {
        return _v[k];
    }

    inline operator json_type &() {
        return _v;
    }

    inline operator json_type const &() const {
        return _v;
    }

    inline JsonObj &operator=(json_type const &r) {
        _v = r;
        return *this;
    }

private:
    json_type _v;
};

extern json_type ToJsonObj(string const &, json_type def = json_type());

extern string ToJson(json_type const &);

ME_NAMESPACE_END

#endif

