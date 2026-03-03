#pragma once
#include <bits/stdc++.h>
#include "../repositories/UserRepository.h"

using namespace std;

class UserService
{
private:
    // You can add private members or methods if needed
    UserRepository userRepository;

public:
    UserService() {} // Default constructor
    void registerUser(User *user)
    {
        userRepository.addUser(user);
    }

    User *getUserByEmail(const string &email)
    {
        return userRepository.getUserByEmail(email);
    }

    vector<User *> getAllUsers()
    {
        return userRepository.getAllUsers();
    }

    User *getUserById(int userId)
    {
        return userRepository.getUserById(userId);
    }
};