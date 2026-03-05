#pragma once
#include "../interfaces/ATMState.h"
#include "../services/ATMService.h"
#include "HasCardState.h"

class IdleState : public ATMState
{
public:
    void insertCard(ATM *atm) override
    {
        cout << "Card inserted\n";
        atm->setState(new HasCardState());
    }

    void enterPIN(ATM *atm, int pin) override
    {
        cout << "Insert card first\n";
    }

    void selectOperation(ATM *atm) override {}

    void withdrawCash(ATM *atm, double amount) override {}

    void checkBalance(ATM *atm) override {}

    void ejectCard(ATM *atm) override {}
};