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
