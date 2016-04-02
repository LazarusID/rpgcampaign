//
// Created by clay on 3/3/16.
//

#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include <memory>

#include "../FileFolder.h"
#include "../Directory.h"

using namespace ::testing;

class MockDirectory : public DirectoryInterface {
public:
    MOCK_METHOD1(OpenDir, void(const char*));
    MOCK_METHOD0(readdir, struct dirent*());
    MOCK_METHOD1(is_regular_file, bool(const char*));
    MOCK_METHOD1(is_directory, bool(const char*));
    MOCK_METHOD1(is_hidden_file, bool(const char*));
    MOCK_METHOD2(link, void(const char*, const char*));
};


class testFileFolder : public testing::Test {
public:
    FileFolder *folder;

    NiceMock<MockDirectory> directory;

    // File Names
    const char* FILE_1 = "first_file.txt";
    const char* FILE_2 = "second_file.txt";
    const char* HIDDEN_FILE = ".hidden";
    const char* DIRECTORY_1 = "directory";

    // Directory entries
    struct dirent ent_file_1;
    struct dirent ent_file_2;
    struct dirent ent_hidden_file;
    struct dirent ent_directory_1;

    virtual void SetUp() {
        folder = new FileFolder(".", &directory);

        ON_CALL(directory, is_regular_file(StrEq(FILE_1)))
                .WillByDefault(Return(true));
        ON_CALL(directory, is_regular_file(StrEq(FILE_2)))
                .WillByDefault(Return(true));
        ON_CALL(directory, is_regular_file(StrEq(HIDDEN_FILE)))
                .WillByDefault(Return(true));
        ON_CALL(directory, is_regular_file(StrEq(DIRECTORY_1)))
                .WillByDefault(Return(false));

        strcpy(ent_file_1.d_name, FILE_1);
        strcpy(ent_file_2.d_name, FILE_2);
        strcpy(ent_hidden_file.d_name, HIDDEN_FILE);
        strcpy(ent_directory_1.d_name, DIRECTORY_1);

    }

};

TEST_F(testFileFolder, getPath_withDefaultConstructor_returnsEmptyString)
{
    FileFolder cut;

    ASSERT_EQ("", cut.getPath());
}

TEST_F(testFileFolder, getPath_withPathConstructor_returnsPath)
{
    unique_ptr<FileFolder> cut = make_unique<FileFolder>(".");

    ASSERT_EQ(".", cut->getPath());
}

TEST_F(testFileFolder, setPath_withValidPath_getPathReturnsSetPath)
{
    // Setup done in class setup
    ASSERT_EQ(".", folder->getPath());
}

TEST_F(testFileFolder, files_withOneRegularFile_willPutFileInList)
{
    EXPECT_CALL(directory, OpenDir(_));
    EXPECT_CALL(directory, readdir())
        .WillOnce(Return(&ent_file_1))
        .WillOnce(Return(nullptr));

    folder->Load();

    ASSERT_THAT(folder->files.size(), Eq(1));
    ASSERT_THAT(folder->files[0], StrEq(FILE_1));

}

TEST_F(testFileFolder, files_withTwoRegularFiles_willPutBothFilesInList)
{
    EXPECT_CALL(directory, OpenDir(_));
    EXPECT_CALL(directory, readdir())
            .WillOnce(Return(&ent_file_1))
            .WillOnce(Return(&ent_file_2))
            .WillOnce(Return(nullptr));

    folder->Load();

    ASSERT_THAT(folder->files.size(), Eq(2));
    ASSERT_THAT(folder->files, Contains(StrEq(FILE_1)));
    ASSERT_THAT(folder->files, Contains(StrEq(FILE_2)));
}

TEST_F(testFileFolder, file_withHiddenFile_willLeaveFileListEmpty)
{
    EXPECT_CALL(directory, OpenDir(_));
    EXPECT_CALL(directory, readdir())
            .WillOnce(Return(&ent_hidden_file))
            .WillOnce(Return(nullptr));

    folder->Load();

    ASSERT_THAT(folder->files.size(), Eq(0));
}

TEST_F(testFileFolder, file_withDirectory_willLeaveFileListEmpty)
{
    EXPECT_CALL(directory, OpenDir(_));
    EXPECT_CALL(directory, readdir())
            .WillOnce(Return(&ent_directory_1))
            .WillOnce(Return(nullptr));

    folder->Load();

    ASSERT_THAT(folder->files.size(), Eq(0));
}
