#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class User
{
private:
    string name;
    int userId;
    string email;
    string phone;

public:
    User(string name, string email, string phone) : name(name), email(email), phone(phone)
    {
        userId = IdGenerator::generateUserId();
    }

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    int getUserId() const { return userId; }
};