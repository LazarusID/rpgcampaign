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

        Json::Value provisionScript = doc["provisionScript"];
        if (provisionScript.isArray()) {
            conf.provisionScript.clear();
            for(int i=0; i < provisionScript.size(); ++i)
            {
                conf.provisionScript.push_back(provisionScript[i].asString());
            }
        }
    }

    return in;
}
