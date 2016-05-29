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
    exe = new Executor;
}

SiteController::SiteController(SystemInterface *injected_system, DirectoryInterface *injected_directory, ExecutorInterface *injected_executor) {
    sys = injected_system;
    dir = injected_directory;
    exe = injected_executor;
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
        if (createSite() != 0) {
            response.error_message = "Unable to Provision Site";
        }
    }

}

int SiteController::createSite() {
    makeSiteFolder();
    exe->setCli(conf.provisionScript);
    map<string, string> parameters;
    parameters["@SITENAME"] = response.fqdn;
    parameters["@USERNAME"] = request.getUsername();
    return exe->run(parameters);
}

string SiteController::sitePath(string fqdn) {
    string fullpath = conf.farmpath + "/" + fqdn;
    return fullpath;
}

void SiteController::makeSiteFolder() {
    dir->mkdir(sitePath(response.fqdn).c_str(), 0755);
}