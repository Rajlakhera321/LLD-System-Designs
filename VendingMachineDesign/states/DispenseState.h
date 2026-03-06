#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IState.h"
#include "../models/VendingMachine.h"
#include "IdleState.h"

using namespace std;

class DispenseState : public IState
{
private:
    static DispenseState *instance;

public:
    static DispenseState *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new DispenseState();
        }
        return instance;
    }

    void insertCoin(VendingMachine *machine, int money) override
    {
        cout << "Currently dispensing. Please wait." << endl;
    }

    void selectProduct(VendingMachine *machine, int code) override
    {
        cout << "Currently dispensing. Please wait." << endl;
    }

    void dispense(VendingMachine *machine) override
    {
        auto item = machine->getInventory()->getItem(machine->getSelectedCode());

        cout << "Dispensing: " << item->getProduct()->getName() << endl;

        int change = machine->getBalance() - item->getProduct()->getPrice();

        if (change > 0)
            cout << "Returning change: " << change << endl;

        machine->resetBalance();

        item->setAvailability(false);
        machine->setState(IdleState::getInstance());
    }

    void cancel(VendingMachine *machine) override
    {
        cout << "Cannot cancel. Currently dispensing." << endl;
    }
};

DispenseState *DispenseState::instance = nullptr;