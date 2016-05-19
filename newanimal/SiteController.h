//
// Created by clay on 4/1/16.
//

#ifndef NEWANIMAL_SITECONTROLLER_H
#define NEWANIMAL_SITECONTROLLER_H

#include <memory>
#include "Config.h"
#include "SiteRequest.h"
#include "SiteResponse.h"
#include "Directory.h"
#include "Directory.h"
#include "System.h"

class SiteController {
private:
    SystemInterface *sys;
    DirectoryInterface *dir;

    string sitePath(string fqdn);

public:

    Config conf;
    SiteResponse response;
    SiteRequest request;

    SiteController();
    SiteController(SystemInterface* injected_system, DirectoryInterface* injected_directory);

    // Load config
    void loadConfig();

    // Validate site name
    void generateResponse();

    // Create site folder
    void makeSiteFolder();

    // Unzip template
    // Template Farm
    // CSS Farm
    // ownership and permissions
    // user setup
};


#endif //NEWANIMAL_SITECONTROLLER_H
