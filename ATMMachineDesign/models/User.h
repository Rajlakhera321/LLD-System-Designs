#pragma once
#include <bits/stdc++.h>

using namespace std;

class User
{
private:
    string name;
    string email;
    string password;

public:
    User(string name, string email, string password)
    {
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
};