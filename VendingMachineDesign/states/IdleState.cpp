#include "IdleState.h"
#include "ReadyState.h"
#include "../models/VendingMachine.h"
#include <iostream>

using namespace std;

IdleState *IdleState::instance = nullptr;

IdleState *IdleState::getInstance()
{
    if (instance == nullptr)
        instance = new IdleState();

    return instance;
}

void IdleState::insertCoin(VendingMachine *machine, int money)
{
    machine->addBalance(money);
    machine->getPaymentInterface()->pay(money);
    machine->setState(ReadyState::getInstance());
}

void IdleState::selectProduct(VendingMachine *, int)
{
    cout << "Insert coin first\n";
}

void IdleState::dispense(VendingMachine *)
{
    cout << "Insert coin first\n";
}

void IdleState::cancel(VendingMachine *)
{
    cout << "Nothing to cancel\n";
}