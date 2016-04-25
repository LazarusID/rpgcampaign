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