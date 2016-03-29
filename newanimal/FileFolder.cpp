//
// Created by clay on 3/3/16.
//

#include "FileFolder.h"

FileFolder::FileFolder() : path(""){
}

FileFolder::FileFolder(string path) : path(path) {

}

string FileFolder::getPath() {
    return path;
}

void FileFolder::setPath(string path) {
    FileFolder::path = path;
}

FileFolder::FileFolder(string path, DirectoryInterface* di) : path(path), directory(di) {

}

void FileFolder::Load() {
    // Do the thing to load the files
    directory->OpenDir(path.c_str());

    struct dirent *filename = nullptr;
    do {
        filename = directory->readdir();
        if (nullptr == filename) continue;
        if ('.' == filename->d_name[0]) continue;
        if (directory->is_regular_file(filename->d_name)) {
            files.push_back(filename->d_name);
        }
    } while(NULL != filename);
}

void FileFolder::init() {
    if (NULL == directory) {
        directory = new Directory();
    }
}