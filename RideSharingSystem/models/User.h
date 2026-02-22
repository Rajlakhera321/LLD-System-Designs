#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class User
{
private:
    int userId;
    string name;
    string phoneNo;

public:
    User(string name, string phoneNo) : name(name), phoneNo(phoneNo)
    {
        userId = IdGenerator::generateUserId();
    }

    int getId() const { return userId; }

    string getName() const { return name; }

    string getPhoneNo() const { return phoneNo; }
};