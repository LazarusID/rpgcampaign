// Represents all of the regular files in a directory
//
// Created by clay on 3/3/16.
//

#ifndef NEWANIMAL_FILEFOLDER_H
#define NEWANIMAL_FILEFOLDER_H

#include <string>
#include <vector>
#include "Directory.h"

using namespace std;

class FileFolder {
private:
    string path;
    DirectoryInterface *directory;

protected:
    void init();

public:

    FileFolder();
    FileFolder(string path);
    FileFolder(string path, DirectoryInterface* di);

    virtual string getPath();
    virtual void setPath(string path);

    virtual void Load();

    vector<string> files;
};


#endif //NEWANIMAL_FILEFOLDER_H
