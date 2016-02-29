//
// Created by clay on 2/27/16.
//

#include "Link.h"

Link::Link() : source(""), destination() {

}

Link::Link(const string &source, const string &destination) : source(source), destination(destination) {
}

const string &Link::getSource() const {
    return source;
}

const string &Link::getDestination() const {
    return destination;
}
