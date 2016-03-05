//
// Created by clay on 3/3/16.
//
#include <sys/stat.h>

#include <string>

#include "Directory.h"

void Directory::OpenDir(const char* path) {
    srcpath = path;
    dir = opendir(path);
}

struct dirent *Directory::readdir() {
    if (NULL == dir) {
        return NULL;
    }
    return ::readdir(dir);
}

bool Directory::is_regular_file(const char *relativepath) {
    struct stat sb;

    string fullpath = srcpath;
    fullpath += '/';
    fullpath += relativepath;

    if (stat(fullpath.c_str(), &sb)) {
        // Don't know what it is, but safe bet we can't see it as a regular file
        return false;
    }

    return S_ISREG(sb.st_mode);
}