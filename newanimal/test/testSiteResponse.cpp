//
// Created by clay on 4/2/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <memory>

#include "../SiteResponse.h"
using namespace ::testing;

static const char *const HOSTNAME = "bobs-burger-shack";
static const char *const FQDN = "bobs-burger-shack.rpg-campaign.net";
static const char *const ERROR_MESSAGE = "My Error";

class testSiteResponse : public testing::Test {
public:
    unique_ptr<SiteResponse> response;

    virtual void SetUp() {
        response = make_unique<SiteResponse>();
        response->hostname = HOSTNAME;
        response->fqdn = FQDN;
    }
};

TEST_F(testSiteResponse, constructor_byDefault_setsBlankErrorHostnameAndFQDN)
{
    response = make_unique<SiteResponse>();

    ASSERT_THAT(response->error_message, StrEq(""));
    ASSERT_THAT(response->hostname, StrEq(""));
    ASSERT_THAT(response->fqdn, StrEq(""));
}

TEST_F(testSiteResponse, copyConstructor_copiesAllFields)
{
    SiteResponse src;
    src.error_message = ERROR_MESSAGE;
    src.hostname = HOSTNAME;
    src.fqdn = FQDN;

    response = make_unique<SiteResponse>(src);

    ASSERT_THAT(response->error_message, StrEq(ERROR_MESSAGE));
    ASSERT_THAT(response->hostname, StrEq(HOSTNAME));
    ASSERT_THAT(response->fqdn, StrEq(FQDN));
}

TEST_F(testSiteResponse, outputOperator_withNoError_createsHostnameNodeButNotErrorNode)
{
    Json::Value out;

    out << *response;

    ASSERT_THAT(out["hostname"].asString(), StrEq(HOSTNAME));
    ASSERT_THAT(out["fqdn"].asString(), StrEq(FQDN));
    ASSERT_FALSE(out.isMember("error"));
}

TEST_F(testSiteResponse, outputOperator_withError_createsHostnameAndErrorNode)
{
    Json::Value out;

    response->error_message = ERROR_MESSAGE;
    out << *response;

    ASSERT_THAT(out["hostname"].asString(), StrEq(HOSTNAME));
    ASSERT_THAT(out["fqdn"].asString(), StrEq(FQDN));
    ASSERT_THAT(out["error"].asString(), StrEq(ERROR_MESSAGE));
}