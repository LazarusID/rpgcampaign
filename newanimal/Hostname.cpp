//
// Created by clay on 3/28/16.
//

#include <cctype>

#include "Hostname.h"

string Hostname::make_hostname(string sitename) {

    string hostname;
    bool lastreplaced = true; // Prevents starting with a dash
    for(char p : sitename) {
        if (!isalnum(p)) {
            if (!lastreplaced) {
                hostname += '-';
            }
            lastreplaced = true;
        } else {
            hostname += tolower(p);
            lastreplaced = false;
        }
    }
    return hostname;
}