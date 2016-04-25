//
// Created by clay on 4/1/16.
//

#include <fstream>
#include "SiteController.h"
#include "Hostname.h"

using namespace std;

SiteController::SiteController() {
    sys = new System;
    dir = new Directory;
}

SiteController::SiteController(SystemInterface *injected_system, DirectoryInterface *injected_directory) {
    sys = injected_system;
    dir = injected_directory;
}

void SiteController::loadConfig() {
    ifstream cf("newanimal.json");
    cf >> conf;
    cf.close();
}

void SiteController::generateResponse() {
    Hostname hn;

    string dirname = hn.make_hostname(request.getSitename());

    if (dir->is_directory(dirname.c_str())) {
        response.error_message = "Site Name Already Exists";
    } else {
        response.hostname = hn.make_hostname(request.getSitename());
    }

}