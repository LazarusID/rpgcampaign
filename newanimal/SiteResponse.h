//
// Created by clay on 4/2/16.
//

#ifndef NEWANIMAL_SITERESPONSE_H
#define NEWANIMAL_SITERESPONSE_H

#include <string>
#include "json/json.h"

using namespace std;

class SiteResponse {
public:

    SiteResponse();
    SiteResponse(const SiteResponse&);

    string hostname;
    string error_message;
};

//Json::Value& operator<<(Json::Value&, SiteResponse&);
//Json::Value& operator>>(Json::Value&, SiteResponse&);

#endif //NEWANIMAL_SITERESPONSE_H
