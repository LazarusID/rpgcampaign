//
// Created by clay on 3/28/16.
//

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "../Hostname.h"

using namespace ::testing;

class testHostname : public testing::Test {
public:
    Hostname sut;
};

TEST_F(testHostname, getName_withNameContainingSpaces_replacesSpacesWithDashes)
{
    ASSERT_THAT(sut.make_hostname("my awesome site"), StrEq("my-awesome-site"));
}

TEST_F(testHostname, getName_withCapitolLetters_usesLowerCaseLetters)
{
    ASSERT_THAT(sut.make_hostname("Awesome"), StrEq("awesome"));
}

TEST_F(testHostname, getName_withNotAlphaNumeric_replacesWithDashes)
{
    ASSERT_THAT(sut.make_hostname("site.name"), StrEq("site-name"));
}

TEST_F(testHostname, getName_withConsecutiveNotAlphaNumeric_replacesWithSingleDash)
{
    ASSERT_THAT(sut.make_hostname("Awesome!+site"), StrEq("awesome-site"));
}

TEST_F(testHostname, getName_withLeadingNonAlphaNumeric_dropsLeadingCharacter)
{
    ASSERT_THAT(sut.make_hostname("@site"), StrEq("site"));
}

TEST_F(testHostname, getName_withTrailingNonAlphaNumeric_dropsTrailingCharacter)
{
    ASSERT_THAT(sut.make_hostname("site@"), StrEq("site"));
}

TEST_F(testHostname, getName_withOnlyNonAlphNum_returnsEmptyString)
{
    ASSERT_THAT(sut.make_hostname("###"), StrEq(""));
}

TEST_F(testHostname, getName_withDroppableCharacters_doesNotContainCharacters)
{
    ASSERT_THAT(sut.make_hostname("my'\"`site"), StrEq("mysite"));
}
