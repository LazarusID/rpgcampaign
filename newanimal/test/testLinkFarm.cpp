//
// Created by clay on 2/27/16.
//

#include <gtest/gtest.h>
#include "../LinkFarm.h"

class testLinkFarm : public testing::Test {
public:
    const string SRC = "/src/path";
    const string DST = "/dst/path";
    const string SFX = "suffix.sfx";

    LinkFarm farm;

    virtual void SetUp()
    {
        farm.setSource_folder(SRC);
        farm.setDestination_folder(DST);
        farm.setDestination_suffix(SFX);
    }
};

TEST_F(testLinkFarm, makeLink_withRelativeFile_appendsFilenameAndSuffixToDestFolder)
{
    const string EXPECTED_DESTINATION = DST + "/localfile/" + SFX;
    auto result = farm.makeLink("localfile.txt");
    ASSERT_EQ(EXPECTED_DESTINATION, result->getDestination());
}

TEST_F(testLinkFarm, makeLink_withNoExtensionOnRelativeFile_appendsFilenameAndSuffixToDestFolder)
{
    const string EXPECTED_DESTINATION = DST + "/localfile/" + SFX;
    auto result = farm.makeLink("localfile");
    ASSERT_EQ(EXPECTED_DESTINATION, result->getDestination());
}

TEST_F(testLinkFarm, makeLink_withTrailingSlashOnDestinationFolder_appendsFilenameAndSuffixWithoutExtraSlash)
{
    const string EXPECTED_DESTINATION = DST + "/localfile/" + SFX;
    farm.setDestination_folder(DST + "/");
    auto result = farm.makeLink("localfile");
    ASSERT_EQ(EXPECTED_DESTINATION, result->getDestination());
}

TEST_F(testLinkFarm, makeLink_withRelativeFile_appendsFilenameToSourceFolder)
{
    const string EXPECTED_SOURCE = SRC + "/localfile.txt";
    auto result = farm.makeLink("localfile.txt");
    ASSERT_EQ(EXPECTED_SOURCE, result->getSource());
}

TEST_F(testLinkFarm, makeLink_withTrailingSlashOnSourceFolder_appendsFilenameToSourceFolderWithoutExtraSlash)
{
    const string EXPECTED_SOURCE = SRC + "/localfile.txt";
    farm.setSource_folder(SRC + "/");
    auto result = farm.makeLink("localfile.txt");
    ASSERT_EQ(EXPECTED_SOURCE, result->getSource());
}

