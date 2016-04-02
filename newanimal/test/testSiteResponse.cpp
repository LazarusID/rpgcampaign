//
// Created by clay on 4/2/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "../SiteResponse.h"
using namespace ::testing;

class testSiteResponse : public testing::Test {
public:
    unique_ptr<SiteResponse> response;

};

TEST_F(testSiteResponse, constructor_byDefault_setsBlankErrorAndHostname)
{
    response = make_unique<SiteResponse>();

    ASSERT_THAT(response->error_message, StrEq(""));
    ASSERT_THAT(response->hostname, StrEq(""));
}

TEST_F(testSiteResponse, copyConstructor_copiesBothFields)
{
    const char *ERROR_MESSAGE = "My Error";
    const char *HOSTNAME = "localhost";

    SiteResponse src;
    src.error_message = ERROR_MESSAGE;
    src.hostname = HOSTNAME;

    response = make_unique<SiteResponse>(src);

    ASSERT_THAT(response->error_message, StrEq(ERROR_MESSAGE));
    ASSERT_THAT(response->hostname, StrEq(HOSTNAME));
}