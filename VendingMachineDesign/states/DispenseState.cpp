#include "DispenseState.h"
#include "IdleState.h"

DispenseState *DispenseState::instance = nullptr;

DispenseState *DispenseState::getInstance()
{
    if (instance == nullptr)
    {
        instance = new DispenseState();
    }
    return instance;
}

void DispenseState::insertCoin(VendingMachine *machine, int money)
{
    cout << "Currently dispensing. Please wait." << endl;
}

void DispenseState::selectProduct(VendingMachine *machine, int code)
{
    cout << "Currently dispensing. Please wait." << endl;
}

void DispenseState::dispense(VendingMachine *machine)
{
    auto item = machine->getInventory()->getItem(machine->getSelectedCode());

    cout << "Dispensing: " << item->getProduct()->getName() << endl;

    int change = machine->getBalance() - item->getProduct()->getPrice();

    if (change > 0)
        cout << "Returning change: " << change << endl;

    machine->resetBalance();

    item->setAvailability(false);
}

void DispenseState::cancel(VendingMachine *machine)
{
    cout << "Cannot cancel. Currently dispensing." << endl;
}