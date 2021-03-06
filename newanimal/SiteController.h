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
#include "Executor.h"

class SiteController {
private:
    SystemInterface *sys;
    DirectoryInterface *dir;
    ExecutorInterface *exe;

    string sitePath(string fqdn);
    int createSite();

public:

    Config conf;
    SiteResponse response;
    SiteRequest request;

    SiteController();
    SiteController(SystemInterface* injected_system, DirectoryInterface* injected_directory,
                   ExecutorInterface* injected_executor);

    // Load config
    void loadConfig();

    // Validate site name
    void generateResponse();

    // Create site folder
    void makeSiteFolder();

};


#endif //NEWANIMAL_SITECONTROLLER_H
