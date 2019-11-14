#include "magdle.h"
#include "json.h"

ME_NAMESPACE_BEGIN

json_type ToJsonObj(string const &str, json_type def) {
    Json::CharReaderBuilder b;
    auto r = b.newCharReader();
    json_type obj;
    JSONCPP_STRING err;
    if (!r->parse(str.c_str(), str.c_str() + str.length(), &obj, &err)) {
        return def;
    }
    return obj;
}

string ToJson(json_type const &jsobj) {
    return jsobj.toStyledString();
}

ME_NAMESPACE_END
