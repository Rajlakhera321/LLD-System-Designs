#pragma once
#include <bits/stdc++.h>
#include "User.h"

using namespace std;

class Account
{
private:
    string accountNumber;
    double balance;
    User *user;

public:
    Account(string accountNumber, double balance, User *user)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->user = user;
    }

    string getAccountNumber() const
    {
        return accountNumber;
    }

    double getBalance() const
    {
        return balance;
    }

    User *getUser() const
    {
        return user;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    bool withdraw(double amount)
    {
        if (amount > balance)
        {
            return false; // Insufficient funds
        }
        balance -= amount;
        return true;
    }
};