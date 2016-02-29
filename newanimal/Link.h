//
// Created by clay on 2/27/16.
//

#ifndef NEWANIMAL_LINK_H
#define NEWANIMAL_LINK_H
#include <string>

using namespace std;

class Link {

private:
    string source;
    string destination;
public:
    Link();
    Link(const string &source, const string &destination);

    const string &getSource() const;

    const string &getDestination() const;

};


#endif //NEWANIMAL_LINK_H
