#pragma once
#include "Account.h"

class Card
{
private:
    int pin;
    Account *account;

public:
    Card(int pin, Account *account)
    {
        this->pin = pin;
        this->account = account;
    }

    bool validatePIN(int enteredPin)
    {
        return enteredPin == pin;
    }

    Account *getAccount()
    {
        return account;
    }
};