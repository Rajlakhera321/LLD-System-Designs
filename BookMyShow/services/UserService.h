#pragma once
#include <bits/stdc++.h>
#include "../models/User.h"
#include "../repositories/UserRepository.h"

using namespace std;

class UserService
{
private:
    UserRepository *userRepo;

public:
    UserService(UserRepository *repo) : userRepo(repo) {}

    User *createUser(string name, string email, string phone)
    {
        User *u = new User(name, email, phone);
        userRepo->addUser(u);
        return u;
    }

    User *getUserById(int id)
    {
        return userRepo->findById(id);
    }

    User *getUserByEmail(string email)
    {
        return userRepo->findByEmail(email);
    }

    User *getUserByName(string name)
    {
        return userRepo->findByName(name);
    }

    vector<User *> getAllUsers()
    {
        return userRepo->findAll(); // if missing, I can add findAll()
    }
};