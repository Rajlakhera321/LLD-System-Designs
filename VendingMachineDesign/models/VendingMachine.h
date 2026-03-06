#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IState.h"
#include "Inventory.h"

using namespace std;

class VendingMachine
{
private:
    IState *currentState;
    Inventory *inventory;
    int balance;
    int selectedCode;

public:
    VendingMachine(IState *state)
    {
        currentState = state;
        inventory = new Inventory();
        balance = 0;
        selectedCode = -1;
    }

    void setState(IState *state)
    {
        currentState = state;
    }

    void addBalance(int amount)
    {
        balance += amount;
    }

    IState *getState()
    {
        return currentState;
    }

    int getBalance()
    {
        return balance;
    }

    void insertCoin(int money)
    {
        currentState->insertCoin(this, money);
    }

    void setSelectedCode(int code)
    {
        selectedCode = code;
    }

    int getSelectedCode()
    {
        return selectedCode;
    }

    Inventory *getInventory()
    {
        return inventory;
    }

    void selectProduct(int code)
    {
        currentState->selectProduct(this, code);
    }

    void dispense()
    {
        currentState->dispense(this);
    }

    void cancel()
    {
        currentState->cancel(this);
    }

    void resetBalance()
    {
        balance = 0;
    }
};