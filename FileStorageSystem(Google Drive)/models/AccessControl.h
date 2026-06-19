#pragma once

#include "bits/stdc++.h"
#include "./File.h"
#include "../enum/Permission.h"

class AccessControl
{
private:
    std::map<std::string, std::unordered_set<Permission> > permissions;

public:
    void grantPermission(const std::string &user, const Permission &permission);

    void revokePermission(const std::string &user, const Permission &permission);

    bool hasPermission(const std::string &user, const Permission &permission) const;
};