#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"

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

    User *getUserByEmail(const string &email)
    {
        for (User *user : users)
        {
            if (user->getEmail() == email)
            {
                return user;
            }
        }
        return nullptr; // User not found
    }

    vector<User *> getAllUsers()
    {
        return users;
    }

    User *getUserById(int userId)
    {
        for (User *user : users)
        {
            if (user->getUserId() == userId)
            {
                return user;
            }
        }
        return nullptr; // User not found
    }
};