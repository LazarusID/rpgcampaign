//
// Created by clay on 4/24/16.
//

#include <gmock/gmock.h>
#include "../SiteController.h"

using namespace testing;

class testSiteController : public ::testing::Test {
public:
    SiteController controller;

    virtual void SetUp() {
        controller.request.setEmail("angus@acdc.com");
        controller.request.setUsername("angus");
        controller.request.setSitename("Back In Black");
    }
};

TEST_F(testSiteController, generateResponse_withSitename_generatesCleanSiteName)
{
    controller.generateResponse();
    ASSERT_THAT(controller.response.hostname, StrEq("back-in-black"));
}