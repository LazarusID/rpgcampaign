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

class SiteController {
public:

    Config conf;
    SiteResponse response;
    SiteRequest request;



    // Load config
    // Validate site name
    // Create site folder
    // Unzip template
    // Template Farm
    // CSS Farm
    // ownership and permissions
    // user setup
};


#endif //NEWANIMAL_SITECONTROLLER_H
