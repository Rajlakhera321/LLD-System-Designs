#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IState.h"
#include "../models/VendingMachine.h"

using namespace std;

class ReadyState : public IState
{
private:
    static ReadyState *instance;

public:
    static ReadyState *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new ReadyState();
        }
        return instance;
    }

    void insertCoin(VendingMachine *machine, int money) override
    {
        machine->addBalance(money);
    }

    void selectProduct(VendingMachine *machine, int code) override
    {
        auto item = machine->getInventory()->getItem(code);

        if (!item || !item->getAvailability())
        {
            cout << "Invalid product code." << endl;
            return;
        }

        if (machine->getBalance() < item->getProduct()->getPrice())
        {
            cout << "Insufficient balance." << endl;
            return;
        }

        machine->setSelectedCode(code);
        machine->dispense();
    }

    void dispense(VendingMachine *machine) override
    {
        // Check if the selected product is available and if the balance is sufficient
        cout << "Dispensing product with code: " << machine->getSelectedCode() << endl;
    }

    void cancel(VendingMachine *machine) override
    {
        cout << "Transaction cancelled. Returning balance: " << machine->getBalance() << endl;
        machine->resetBalance();
    }
};

ReadyState *ReadyState::instance = nullptr;