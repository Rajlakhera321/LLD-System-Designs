#pragma once
#include <bits/stdc++.h>
#include "Book.h"
#include "../enums/UserRole.h"
#include "IDGenerator.h"
#include "../observers/Observer.h"

class User : public Observer
{
private:
    int id;
    std::string username;
    UserRole role;
    vector<int> history;

public:
    User(std::string name, UserRole r) : username(name), role(r)
    {
        id = IDGenerator::generateUserId();
    }

    void notify(const std::string &message) override
    {
        std::cout << "[NOTIFY " << username << "] " << message << std::endl;
    }

    std::string getName() const
    {
        return username;
    }

    int getId() const { return id; }
    UserRole getRole() const { return role; }

    void addToHistory(int copyId)
    {
        history.push_back(copyId);
    }
};