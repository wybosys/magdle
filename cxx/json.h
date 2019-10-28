#ifndef _ME_JSON_H
#define _ME_JSON_H

#include <jsoncpp/json/json.h>

ME_NAMESPACE_BEGIN

typedef Json::Value json_type;

extern json_type ToJsonObj(string const&, json_type def = json_type());
extern string ToJson(json_type const&);

ME_NAMESPACE_END

#endif

