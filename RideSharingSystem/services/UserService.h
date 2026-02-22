#pragma once
#include <bits/stdc++.h>
#include "models/User.h"
#include "repositories/UserRepository.h"

using namespace std;

class UserService
{
private:
    UserRepository *userRepo;

public:
    UserService(UserRepository *userRepo) : userRepo(userRepo) {}

    void registerUser(string name, string phoneNo)
    {
        User *user = new User(name, phoneNo);
        userRepo->addUser(user);
    }

    User *getUserById(int id)
    {
        return userRepo->getUserById(id);
    }

    vector<User *> getAllUsers()
    {
        return userRepo->getAllUsers();
    }
};