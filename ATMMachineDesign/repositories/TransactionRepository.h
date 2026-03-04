#pragma once
#include <bits/stdc++.h>
#include "../models/Transactions.h"

using namespace std;

class TransactionRepository
{
private:
    vector<Transactions *> transactions;

public:
    void addTransaction(Transactions *transaction)
    {
        transactions.push_back(transaction);
        transaction->getToAccount()->getUser()->update(transaction->getAmount()); // Notify the user of the toAccount about the debit transaction
    }

    vector<Transactions *> getAllTransactions()
    {
        return transactions;
    }

    Transactions *getTransactionById(int transactionId)
    {
        for (Transactions *transaction : transactions)
        {
            if (transaction->getTransactionId() == transactionId)
            {
                return transaction;
            }
        }
        return nullptr; // Transaction not found
    }

    Transactions *getTransactionByType(TransactionEnum type)
    {
        for (Transactions *transaction : transactions)
        {
            if (transaction->getTransactionType() == type)
            {
                return transaction;
            }
        }
        return nullptr; // Transaction not found
    }
};