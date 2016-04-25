//
// Created by clay on 4/24/16.
//

#include <gmock/gmock.h>
#include "../Directory.h"

class MockDirectory : public DirectoryInterface {
public:
    MOCK_METHOD1(OpenDir, void(const char*));
    MOCK_METHOD0(readdir, struct dirent*());
    MOCK_METHOD1(is_regular_file, bool(const char*));
    MOCK_METHOD1(is_directory, bool(const char*));
    MOCK_METHOD1(is_hidden_file, bool(const char*));
    MOCK_METHOD2(link, void(const char*, const char*));
};
