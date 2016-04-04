//
// Created by clay on 3/28/16.
//

#include <cctype>

#include "Hostname.h"

string Hostname::make_hostname(string sitename) {

    string hostname;
    bool lastreplaced = true; // Prevents starting with a dash
    for(char p : sitename) {
        if (is_droppable(p)) {
            continue;
        }
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
    if ('-' == hostname[hostname.length() - 1]) {
        hostname.erase(hostname.length() - 1, 1);
    }
    return hostname;
}

bool Hostname::is_droppable(char c) {
    switch(c) {
        case '\'':
        case '\"':
        case '`':
            return true;
        default:
            return false;
    }
}