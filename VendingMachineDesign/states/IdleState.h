#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IState.h"

using namespace std;

class IdleState : public IState
{
private:
    static IdleState *instance;

public:
    static IdleState *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new IdleState();
        }
        return instance;
    }

    void insertCoin(VendingMachine *machine, int money) override
    {
        machine->addBalance(money);
    }

    void selectProduct(VendingMachine *machine, int code) override
    {
        cout << "Please insert coin first." << endl;
    }

    void dispense(VendingMachine *machine) override
    {
        cout << "Please insert coin first." << endl;
    }

    void cancel(VendingMachine *machine) override
    {
        cout << "No transaction to cancel." << endl;
    }
};

IdleState *IdleState::instance = nullptr;