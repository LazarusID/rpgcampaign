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

    struct dirent *filename = directory->readdir();
    files.push_back(filename->d_name);
}

void FileFolder::init() {
    if (NULL == directory) {
        directory = new Directory();
    }
}