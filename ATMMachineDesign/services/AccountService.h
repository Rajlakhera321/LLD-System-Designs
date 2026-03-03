#pragma once
#include <bits/stdc++.h>
#include "../repositories/AccountRepository.h"

using namespace std;

class AccountService
{
private:
    // You can add private members or methods if needed
    AccountRepository accountRepository;
    static AccountService *instance;

    AccountService(AccountRepository *repo) : accountRepository(*repo) {} // Private constructor to prevent instantiation

public:
    static AccountService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new AccountService(new AccountRepository());
        }
        return instance;
    }

    void createAccount(Account *account)
    {
        accountRepository.addAccount(account);
    }

    Account *getAccountByNumber(const string &accountNumber)
    {
        return accountRepository.getAccountByNumber(accountNumber);
    }

    vector<Account *> getAllAccounts()
    {
        return accountRepository.getAllAccounts();
    }

    Account *getAccountById(int id)
    {
        return accountRepository.getAccountById(id);
    }
};

AccountService *AccountService::instance = nullptr; // Initialize static member