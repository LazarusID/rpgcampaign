//
// Created by clay on 4/3/16.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <sstream>

#include "../Config.h"

using namespace ::testing;

class testConfig : public ::testing::Test {
public:
    Config conf;
};

TEST_F(testConfig, instream_withFullConfig_populatesConfig)
{
    istringstream in("{ \"domain\": \"example.com\", \"farmpath\": \"/var/farm\" }");

    in >> conf;

    ASSERT_THAT(conf.domain, StrEq("example.com"));
    ASSERT_THAT(conf.farmpath, StrEq("/var/farm"));
}

TEST_F(testConfig, instream_withMissingFarmPath_leavesFarmpathEmpty)
{
    istringstream in("{ \"domain\": \"example.com\" }");

    in >> conf;

    ASSERT_THAT(conf.domain, StrEq("example.com"));
    ASSERT_THAT(conf.farmpath, StrEq(""));
}

TEST_F(testConfig, instream_withMissingDomain_leavesDomainEmpty)
{
    istringstream in("{ \"farmpath\": \"/var/farm\" }");

    in >> conf;

    ASSERT_THAT(conf.domain, StrEq(""));
    ASSERT_THAT(conf.farmpath, StrEq("/var/farm"));
}

TEST_F(testConfig, instream_withProvisionScript_populatesProvisionScript)
{
    istringstream in("{ \"provisionScript\": [\"program\", \"arg1\", \"arg2\" ] }");
    in >> conf;

    ASSERT_THAT(conf.provisionScript, ElementsAre("program", "arg1", "arg2"));
}
