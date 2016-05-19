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

    string hostname = hn.make_hostname(request.getSitename());
    string fqdn = hostname + "." + conf.domain;

    if (dir->is_directory(sitePath(fqdn).c_str())) {
        response.error_message = "Site Name Already Exists";
    } else {
        response.hostname = hostname;
        response.fqdn = fqdn;
        makeSiteFolder();
    }

}

string SiteController::sitePath(string fqdn) {
    string fullpath = conf.farmpath + "/" + fqdn;
    return fullpath;
}

void SiteController::makeSiteFolder() {
    dir->mkdir(sitePath(response.fqdn).c_str(), 0755);
}