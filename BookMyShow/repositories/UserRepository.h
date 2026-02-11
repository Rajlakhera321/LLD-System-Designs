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

    User *findById(int id)
    {
        for (auto u : users)
            if (u->getUserId() == id)
                return u;
        return nullptr;
    }

    User *findByName(string name)
    {
        for (auto u : users)
            if (u->getName() == name)
                return u;
        return nullptr;
    }

    User *findByEmail(string email)
    {
        for (auto u : users)
            if (u->getEmail() == email)
                return u;
        return nullptr;
    }

    vector<User *> findAll() const
    {
        return users;
    }
};