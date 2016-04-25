//
// Created by clay on 4/1/16.
//

#include <fstream>
#include "SiteController.h"
#include "Hostname.h"

using namespace std;

void SiteController::loadConfig() {
    // Do your load thang
    ifstream cf("newanimal.json");
    cf >> conf;
    cf.close();
}

void SiteController::generateResponse() {
    Hostname hn;

    response.hostname = hn.make_hostname(request.getSitename());
}