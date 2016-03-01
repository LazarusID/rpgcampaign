//
// Created by clay on 2/27/16.
//
#include <sstream>
#include "LinkFarm.h"

LinkFarm::LinkFarm(const string source_folder, const string destination_folder) : source_folder(source_folder),
                                                                    destination_folder(destination_folder) {
}

LinkFarm::LinkFarm() : source_folder(""), destination_folder("") {

}


const string &LinkFarm::getSource_folder() const {
    return source_folder;
}

void LinkFarm::setSource_folder(const string &source_folder) {
    LinkFarm::source_folder = source_folder;
}

const string &LinkFarm::getDestination_folder() const {
    return destination_folder;
}

void LinkFarm::setDestination_folder(const string &destination_folder) {
    LinkFarm::destination_folder = destination_folder;
}

unique_ptr<Link> LinkFarm::makeLink(const string &filename) {

    string destination = build_destination_path(filename);
    string source = build_source_path(filename);

    return make_unique<Link>(source, destination);
}

string LinkFarm::build_destination_path(const string right) const {
    ostringstream newpath;

    size_t period = right.find_last_of('.');
    string basename = right.substr(0, period);

    newpath << full_folder_path(destination_folder) << basename << '/' << destination_suffix;
    return newpath.str();
}

string LinkFarm::build_source_path(const string filename) const {
    ostringstream newpath;
    newpath << full_folder_path(source_folder) << filename;
    return newpath.str();
}

const string &LinkFarm::getDestination_suffix() const {
    return destination_suffix;
}

void LinkFarm::setDestination_suffix(const string &destination_suffix) {
    LinkFarm::destination_suffix = destination_suffix;
}

string LinkFarm::full_folder_path(const string folder) const {
    ostringstream full_folder;
    full_folder << folder;
    if (folder[folder.size() - 1] != '/') {
        full_folder << '/';
    }
    return full_folder.str();
}
