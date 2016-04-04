//
// Created by clay on 4/3/16.
//

#include "Config.h"
#include "json/json.h"

istream& operator>>(istream& in, Config& conf)
{
    if (in) {
        Json::Value doc;
        in >> doc;

        conf.farmpath = doc["farmpath"].asString();
        conf.domain = doc["domain"].asString();
    }

    return in;
}
