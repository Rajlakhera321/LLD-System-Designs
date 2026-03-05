#pragma once
#include <iostream>

class ATM;

class ATMState
{
public:
    virtual void insertCard(ATM *atm) = 0;
    virtual void enterPIN(ATM *atm, int pin) = 0;
    virtual void selectOperation(ATM *atm) = 0;
    virtual void withdrawCash(ATM *atm, double amount) = 0;
    virtual void checkBalance(ATM *atm) = 0;
    virtual void ejectCard(ATM *atm) = 0;

    virtual ~ATMState() = default;
};