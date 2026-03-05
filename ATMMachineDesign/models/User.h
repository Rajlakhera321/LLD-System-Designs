#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class User
{
private:
    int userId;
    string name;
    string email;
    string password;

public:
    User(string name, string email, string password)
    {
        this->userId = IdGenerator::generateUserId();
        this->name = name;
        this->email = email;
        this->password = password;
    }

    string getName() const
    {
        return name;
    }

    string getEmail() const
    {
        return email;
    }

    string getPassword() const
    {
        return password;
    }

    int getUserId() const
    {
        return userId;
    }
};