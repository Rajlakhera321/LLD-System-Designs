#include "ReadyState.h"
#include "DispenseState.h"
#include "../models/VendingMachine.h"
#include <iostream>

using namespace std;

ReadyState *ReadyState::instance = nullptr;

ReadyState *ReadyState::getInstance()
{
    if (instance == nullptr)
        instance = new ReadyState();

    return instance;
}

void ReadyState::insertCoin(VendingMachine *machine, int money)
{
    machine->addBalance(money);
}

void ReadyState::selectProduct(VendingMachine *machine, int code)
{
    auto item = machine->getInventory()->getItem(code);

    if (!item || item->getAvailability() == 0)
    {
        cout << "Item not available\n";
        return;
    }

    if (machine->getBalance() < item->getProduct()->getPrice())
    {
        cout << "Insufficient balance\n";
        return;
    }

    machine->setSelectedCode(code);
    machine->setState(DispenseState::getInstance());
    machine->dispense();
}

void ReadyState::dispense(VendingMachine *)
{
    cout << "Select product first\n";
}

void ReadyState::cancel(VendingMachine *machine)
{
    cout << "Returning " << machine->getBalance() << endl;
    machine->resetBalance();
}