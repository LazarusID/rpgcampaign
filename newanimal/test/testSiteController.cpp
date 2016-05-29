//
// Created by clay on 4/24/16.
//

#include <gmock/gmock.h>
#include "../SiteController.h"

#include "MockSystem.h"
#include "MockDirectory.h"
#include "MockExecutor.h"

using namespace testing;

static const char *const USERNAME = "angus";
static const char *const SITE_FQDN = "back-in-black.rpg-campaign.us";

class testSiteController : public ::testing::Test {
public:
    SiteController *controller;
    MockDirectory mockDir;
    MockSystem mockSys;
    MockExecutor mockExe;

    virtual void SetUp() {
        controller = new SiteController(&mockSys, &mockDir, &mockExe);
        controller->request.setEmail("angus@acdc.com");
        controller->request.setUsername(USERNAME);
        controller->request.setSitename("Back In Black");

        controller->conf.domain = "rpg-campaign.us";
        controller->conf.farmpath = "/var/farm";
        controller->conf.provisionScript.push_back("makeanimal.sh");
        controller->conf.provisionScript.push_back("-s");
        controller->conf.provisionScript.push_back("@SITENAME");
        controller->conf.provisionScript.push_back("-u");
        controller->conf.provisionScript.push_back("@USERNAME");
    }
};

TEST_F(testSiteController, generateResponse_withSitename_generatesCleanSiteName)
{
    controller->generateResponse();
    ASSERT_THAT(controller->response.hostname, StrEq("back-in-black"));
    ASSERT_THAT(controller->response.fqdn, StrEq(SITE_FQDN));
}

TEST_F(testSiteController, generateResponse_withDuplicateSitename_generatesError) {
    EXPECT_CALL(mockDir, is_directory(_)).WillOnce(Return(1));
    controller->generateResponse();
    ASSERT_THAT(controller->response.error_message, StrEq("Site Name Already Exists"));
}

TEST_F(testSiteController, generateResponse_withSitename_createsSiteFolder) {
    const char *expected_dir = "/var/farm/back-in-black.rpg-campaign.us";
    mode_t expected_mode = 0755;
    EXPECT_CALL(mockDir, mkdir(StrEq(expected_dir), expected_mode)).WillOnce(Return(0));
    controller->generateResponse();
}

TEST_F(testSiteController, generateResponse_withSitename_runsProvisionScript) {
    map<string, string> params;
    EXPECT_CALL(mockExe, run(_))
                .WillOnce(DoAll(SaveArg<0>(&params), Return(0)));
    controller->generateResponse();
    ASSERT_THAT(params["@SITENAME"], StrEq(SITE_FQDN));
    ASSERT_THAT(params["@USERNAME"], StrEq(USERNAME));
}

TEST_F(testSiteController, generateResponse_whenProvisionScriptFails_returnsErrorResponse)
{
    EXPECT_CALL(mockExe, run(_)).WillOnce(Return(1));
    controller->generateResponse();

    ASSERT_THAT(controller->response.error_message, StrEq("Unable to Provision Site"));
}