#pragma once
#include <bits/stdc++.h>
#include "../repositories/TransactionRepository.h"

using namespace std;

class TransactionService
{
private:
    // You can add private members or methods if needed
    TransactionRepository transactionRepository;
    static TransactionService *instance;

    TransactionService(TransactionRepository *repo) : transactionRepository(*repo) {} // Private constructor to prevent instantiation

public:
    static TransactionService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new TransactionService(new TransactionRepository());
        }
        return instance;
    }

    void createTransaction(Transactions *transaction)
    {
        transactionRepository.addTransaction(transaction);
    }

    vector<Transactions *> getAllTransactions()
    {
        return transactionRepository.getAllTransactions();
    }

    Transactions *getTransactionById(int transactionId)
    {
        return transactionRepository.getTransactionById(transactionId);
    }

    Transactions *getTransactionByType(TransactionEnum type)
    {
        return transactionRepository.getTransactionByType(type);
    }
};

TransactionService *TransactionService::instance = nullptr; // Initialize static member