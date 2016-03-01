//
// Created by Clay Dowling on 3/1/16.
//

#ifndef NEWANIMAL_SITEREQUEST_H
#define NEWANIMAL_SITEREQUEST_H

#include <string>
#include "json/json.h"

using namespace std;

class SiteRequest {
private:
    string username;
    string email;
    string sitename;
public:

    SiteRequest();
    SiteRequest(string username, string email, string sitename);

    const string &getUsername() const;
    void setUsername(const string &username);

    const string &getEmail() const;
    void setEmail(const string &email);

    const string &getSitename() const;
    void setSitename(const string &sitename);
};

Json::Value& operator<<(Json::Value&, SiteRequest&);
Json::Value& operator>>(Json::Value&, SiteRequest&);

#endif //NEWANIMAL_SITEREQUEST_H
