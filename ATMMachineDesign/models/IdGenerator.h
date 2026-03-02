#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int accountId;
    static int transactionId;
    static int userId;

    static int generateTransactionId() { return ++transactionId; }

    static int generateUserId() { return ++userId; }

    static int generateAccountId() { return ++accountId; }
};

int IdGenerator::transactionId = 0;
int IdGenerator::userId = 0;
int IdGenerator::accountId = 0;