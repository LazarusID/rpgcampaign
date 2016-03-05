//
// Created by clay on 3/3/16.
//

#ifndef NEWANIMAL_DIRECTORY_H
#define NEWANIMAL_DIRECTORY_H

#include <sys/types.h>
#include <dirent.h>

#include <string>

using namespace std;

class DirectoryInterface {

public:

    virtual void OpenDir(const char*) = 0;
    virtual struct dirent* readdir() = 0;
    virtual bool is_regular_file(const char *) = 0;
};


class Directory : public DirectoryInterface {
private:
    DIR* dir;
    const char *srcpath;

public:

    virtual void OpenDir(const char* path);
    virtual struct dirent* readdir();
    virtual bool is_regular_file(const char *relativepath);

};


#endif //NEWANIMAL_DIRECTORY_H
