#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class User
{
private:
    int id;
    string name;
    string phoneNo;

public:
    User(string name, string phoneNo) : name(name), phoneNo(phoneNo)
    {
        id = IdGenerator::generateUserId();
    }

    int id() const { return id; }

    string getName() const { return name; }

    string getPhoneNo() const { return phoneNo; }
};