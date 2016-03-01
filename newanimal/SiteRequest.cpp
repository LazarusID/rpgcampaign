//
// Created by Clay Dowling on 3/1/16.
//

#include "SiteRequest.h"


const string &SiteRequest::getUsername() const {
    return username;
}

void SiteRequest::setUsername(const string &username) {
    SiteRequest::username = username;
}

const string &SiteRequest::getEmail() const {
    return email;
}

void SiteRequest::setEmail(const string &email) {
    SiteRequest::email = email;
}

const string &SiteRequest::getSitename() const {
    return sitename;
}

void SiteRequest::setSitename(const string &sitename) {
    SiteRequest::sitename = sitename;
}

SiteRequest::SiteRequest()  = default;

SiteRequest::SiteRequest(string username, string email, string sitename) :
    username(username), email(email), sitename(sitename)
{};
