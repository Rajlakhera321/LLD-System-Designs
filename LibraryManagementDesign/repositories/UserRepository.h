#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"

using namespace std;

class UserRepository
{
public:
    vector<User *> users;

    void add(User *u) { users.push_back(u); }

    User *findById(int id)
    {
        for (auto u : users)
            if (u->getId() == id)
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
};