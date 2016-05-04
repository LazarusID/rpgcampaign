//
// Created by clay on 4/24/16.
//

#include <gmock/gmock.h>
#include "../SiteController.h"

#include "MockSystem.h"
#include "MockDirectory.h"

using namespace testing;

class testSiteController : public ::testing::Test {
public:
    SiteController *controller;
    MockDirectory mockDir;
    MockSystem mockSys;

    virtual void SetUp() {
        controller = new SiteController(&mockSys, &mockDir);
        controller->request.setEmail("angus@acdc.com");
        controller->request.setUsername("angus");
        controller->request.setSitename("Back In Black");

	controller->conf.domain = "rpg-campaign.us";
	controller->conf.farmpath = "/var/farm";
    }
};

TEST_F(testSiteController, generateResponse_withSitename_generatesCleanSiteName)
{
    controller->generateResponse();
    ASSERT_THAT(controller->response.hostname, StrEq("back-in-black"));
}

TEST_F(testSiteController, generateResponse_withDuplicateSitename_generatesError)
{
    EXPECT_CALL(mockDir, is_directory(_)).WillOnce(Return(1));
    controller->generateResponse();
    ASSERT_THAT(controller->response.error_message, StrEq("Site Name Already Exists"));
}

TEST_F(testSiteController, generateResponse_withSitename_createsSiteFolder)
{
	const char* expected_dir = "/var/farm/back-in-black";
	mode_t expected_mode = 0755;
	EXPECT_CALL(mockDir, mkdir(StrEq(expected_dir), expected_mode)).WillOnce(Return(0));
    controller->generateResponse();
}
