#pragma once
#include <bits/stdc++.h>
#include "models/User.h"

using namespace std;

class UserRepository
{
private:
    vector<User *> users;

public:
    void addUser(User *user)
    {
        users.push_back(user);
    }

    User *getUserById(int id)
    {
        for (auto user : users)
        {
            if (user->getId() == id)
            {
                return user;
            }
        }
        return nullptr;
    }

    vector<User *> getAllUsers()
    {
        return users;
    }
};