//
// Created by clay on 4/2/16.
//

#include "SiteResponse.h"

SiteResponse::SiteResponse() {
    error_message = "";
    hostname = "";
}

SiteResponse::SiteResponse(const SiteResponse &rhs) : error_message(rhs.error_message), hostname(rhs.hostname){

}

Json::Value& operator<<(Json::Value& out, SiteResponse& response)
{
    out["hostname"] = response.hostname;
    if ("" != response.error_message) {
        out["error"] = response.error_message;
    }
    return out;
}
