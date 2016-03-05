//
// Created by Clay Dowling on 3/1/16.
//

#include <gtest/gtest.h>
#include <sstream>
#include "../SiteRequest.h"

using namespace std;

class testSiteRequest : public testing::Test {
public:
    SiteRequest sr;

    const string EMAIL = "bob@mailinator.org";
    const string USERNAME = "bob";
    const string SITENAME = "Bob's Game Shack";

    virtual void SetUp()
    {
        sr.setSitename(SITENAME);
        sr.setEmail(EMAIL);
        sr.setUsername(USERNAME);
    }
};

TEST_F(testSiteRequest, outputToJson_withHealthySiteRequest_returnsProperlySerializedSiteRequest)
{
    Json::Value root;
    root << sr;
    ostringstream out;
    out << root;

    Json::Value check;
    istringstream in(out.str());
    in >> check;

    ASSERT_EQ(EMAIL, check["email"].asString());
    ASSERT_EQ(USERNAME, check["username"].asString());
    ASSERT_EQ(SITENAME, check["sitename"].asString());

}