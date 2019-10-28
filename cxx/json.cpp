#include "magdle.h"
#include "json.h"

ME_NAMESPACE_BEGIN

json_type ToJsonObj(string const& str, json_type def) {
    Json::Reader r;
    json_type obj;
    if (!r.parse(str, obj)) {
        return def;
    }
    return obj;
}

string ToJson(json_type const& jsobj) {
    Json::FastWriter w;
    return w.write(jsobj);
}

ME_NAMESPACE_END
