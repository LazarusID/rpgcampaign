//
// Created by clay on 2/27/16.
//

#ifndef NEWANIMAL_LINKFARM_H
#define NEWANIMAL_LINKFARM_H

#include <string>
#include <memory>

#include "Link.h"

using namespace std;

class LinkFarm {

private:
    string source_folder;
    string destination_folder;
    string destination_suffix;

protected:
    string build_destination_path(const string) const;
    string build_source_path(const string) const;
    string full_folder_path(const string) const;

public:
    LinkFarm();
    LinkFarm(const string source_folder, const string destination_folder);

    const string &getSource_folder() const;

    void setSource_folder(const string &source_folder);

    const string &getDestination_folder() const;

    void setDestination_folder(const string &destination_folder);

    const string &getDestination_suffix() const;

    void setDestination_suffix(const string &destination_suffix);

    unique_ptr<Link> makeLink(const string &source);

};


#endif //NEWANIMAL_LINKFARM_H
