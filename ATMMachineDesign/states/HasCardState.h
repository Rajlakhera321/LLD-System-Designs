#pragma once
#include "../interfaces/ATMState.h"
#include "../services/ATMService.h"
#include "AuthenticatedState.h"
#include "IdleState.h"

class HasCardState : public ATMState
{
public:
    void insertCard(ATM *atm) override
    {
        cout << "Card already inserted\n";
    }

    void enterPIN(ATM *atm, int pin) override
    {
        if (atm->getCard()->validatePIN(pin))
        {
            cout << "PIN correct\n";
            atm->setState(new AuthenticatedState());
        }
        else
        {
            cout << "Wrong PIN\n";
        }
    }

    void selectOperation(ATM *atm) override {}

    void withdrawCash(ATM *atm, double amount) override {}

    void checkBalance(ATM *atm) override {}

    void ejectCard(ATM *atm) override
    {
        cout << "Card ejected\n";
        atm->setState(new IdleState());
    }
};