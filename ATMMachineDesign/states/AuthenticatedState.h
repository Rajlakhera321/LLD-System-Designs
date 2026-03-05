#pragma once
#include "../interfaces/ATMState.h"
#include "../services/ATMService.h"
#include "IdleState.h"

class AuthenticatedState : public ATMState
{
public:
    void insertCard(ATM *atm) override {}

    void enterPIN(ATM *atm, int pin) override {}

    void selectOperation(ATM *atm) override
    {
        cout << "Select operation\n";
    }

    void withdrawCash(ATM *atm, double amount) override
    {
        auto account = atm->getCard()->getAccount();

        if (account->withdraw(amount) && atm->getCash() >= amount)
        {
            atm->dispenseCash(amount);
        }
        else
        {
            cout << "Transaction failed\n";
        }
    }

    void checkBalance(ATM *atm) override
    {
        cout << "Balance: "
             << atm->getCard()->getAccount()->getBalance()
             << endl;
    }

    void ejectCard(ATM *atm) override
    {
        cout << "Card ejected\n";
        atm->setState(new IdleState());
    }
};