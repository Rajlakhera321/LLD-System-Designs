#include "./AccessControl.h"

void AccessControl::grantPermission(const std::string &user, const Permission &permission)
{
    permissions[user].insert(permission);
}

void AccessControl::revokePermission(const std::string &user, const Permission &permission)
{
    if (permissions.find(user) != permissions.end())
    {
        permissions[user].erase(permission);
        if (permissions[user].empty())
        {
            permissions.erase(user);
        }
    }
}

bool AccessControl::hasPermission(const std::string &user, const Permission &permission) const
{
    auto it = permissions.find(user);
    if (it != permissions.end())
    {
        return it->second.find(permission) != it->second.end();
    }
    return false;
}