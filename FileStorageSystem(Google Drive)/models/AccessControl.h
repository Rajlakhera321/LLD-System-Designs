#pragma once

#include "bits/stdc++.h"
#include "./File.h"

class AccessControl
{
private:
    std::map<std::string, std::set<std::string> > permissions;

public:
    void grantPermission(const std::string &user, const std::string &permission);

    void revokePermission(const std::string &user, const std::string &permission);

    bool hasPermission(const std::string &user, const std::string &permission) const;
};