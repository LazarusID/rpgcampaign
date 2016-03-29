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

SiteRequest::SiteRequest(const SiteRequest& rhs) : username(rhs.username), email(rhs.email), sitename(rhs.sitename) {
}

SiteRequest::SiteRequest(string username, string email, string sitename) :
    username(username), email(email), sitename(sitename)
{};


// Input and output operators

Json::Value& operator<<(Json::Value& json, SiteRequest& sr)
{
    json["username"] = sr.getUsername();
    json["email"] = sr.getEmail();
    json["sitename"] = sr.getSitename();
    return json;
}

Json::Value& operator>>(Json::Value& json, SiteRequest& sr)
{
    string email;
    string sitename;
    string username;

    email = json["email"].asString();
    sitename = json["sitename"].asString();
    username = json["username"].asString();

    sr.setEmail(email);
    sr.setUsername(username);
    sr.setSitename(sitename);

    return json;
}