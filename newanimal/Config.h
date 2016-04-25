//
// Created by clay on 4/3/16.
//

#ifndef NEWANIMAL_CONFIG_H
#define NEWANIMAL_CONFIG_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Config {
public:
    string domain;
    string farmpath;

};

istream& operator>>(istream& in, Config& conf);

#endif //NEWANIMAL_CONFIG_H
