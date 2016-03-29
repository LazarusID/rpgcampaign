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

    string fullpath = make_fullpath(relativepath);

    if (stat(fullpath.c_str(), &sb)) {
        // Don't know what it is, but safe bet we can't see it as a regular file
        return false;
    }

    return S_ISREG(sb.st_mode);
}

bool Directory::is_directory(const char *relativepath) {
    struct stat sb;

    string fullpath = make_fullpath(relativepath);
    if (stat(fullpath.c_str(), &sb)) {
        // Don't know what it is, but safe bet we can't see it as a directory
        return false;
    }

    return S_ISDIR(sb.st_mode);

}

bool Directory::is_hidden_file(const char *relativepath) {
    if (nullptr == relativepath) {
        return false;
    }
    return '.' == relativepath[0];
}

string Directory::make_fullpath(const char *relativepath) {

    string fullpath = srcpath;
    fullpath += '/';
    fullpath += relativepath;

    return fullpath;
}