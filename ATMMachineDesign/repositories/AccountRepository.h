#pragma once
#include <bits/stdc++.h>
#include "../models/Account.h"

using namespace std;

class AccountRepository
{
private:
    vector<Account *> accounts;

public:
    void addAccount(Account *account)
    {
        accounts.push_back(account);
    }

    Account *getAccountByNumber(const string &accountNumber)
    {
        for (Account *account : accounts)
        {
            if (account->getAccountNumber() == accountNumber)
            {
                return account;
            }
        }
        return nullptr; // Account not found
    }

    vector<Account *> getAllAccounts()
    {
        return accounts;
    }

    Account *getAccountById(int id)
    {
        for (Account *account : accounts)
        {
            if (account->getUser()->getUserId() == id)
            {
                return account;
            }
        }
        return nullptr; // Account not found
    }
};