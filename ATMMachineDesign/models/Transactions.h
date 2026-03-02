#pragma once
#include <bits/stdc++.h>
#include "Account.h"
#include "IdGenerator.h"
#include "../enums/TransactionEnum.h"

using namespace std;

class Transactions
{
private:
    int transactionId;
    Account *fromAccount;
    Account *toAccount;
    double amount;
    TransactionEnum transactionType;

public:
    Transactions(Account *fromAccount, Account *toAccount, double amount, TransactionEnum transactionType)
    {
        this->transactionId = IdGenerator::generateTransactionId();
        this->fromAccount = fromAccount;
        this->toAccount = toAccount;
        this->amount = amount;
        this->transactionType = transactionType;
    }

    Account *getFromAccount() const
    {
        return fromAccount;
    }

    Account *getToAccount() const
    {
        return toAccount;
    }

    double getAmount() const
    {
        return amount;
    }

    TransactionEnum getTransactionType() const
    {
        return transactionType;
    }

    int getTransactionId() const
    {
        return transactionId;
    }
};