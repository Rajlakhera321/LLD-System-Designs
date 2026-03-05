#pragma once
#include "../interfaces/ATMState.h"
#include "../models/Card.h"

class ATM
{
private:
    ATMState *currentState;
    Card *insertedCard;
    double cashAvailable;

public:
    ATM(ATMState *state, double cash)
    {
        currentState = state;
        cashAvailable = cash;
        insertedCard = nullptr;
    }

    void setState(ATMState *state)
    {
        currentState = state;
    }

    ATMState *getState()
    {
        return currentState;
    }

    void setCard(Card *card)
    {
        insertedCard = card;
    }

    Card *getCard()
    {
        return insertedCard;
    }

    double getCash()
    {
        return cashAvailable;
    }

    void dispenseCash(double amount)
    {
        cashAvailable -= amount;
        cout << "Dispensed: " << amount << endl;
    }

    void insertCard()
    {
        currentState->insertCard(this);
    }

    void enterPIN(int pin)
    {
        currentState->enterPIN(this, pin);
    }

    void withdraw(double amount)
    {
        currentState->withdrawCash(this, amount);
    }

    void balance()
    {
        currentState->checkBalance(this);
    }

    void eject()
    {
        currentState->ejectCard(this);
    }
};