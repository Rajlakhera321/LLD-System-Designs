#include <iostream>
#include <vector>
#include <string>
#include "states/IdleState.h"
#include "models/VendingMachine.h"
#include "models/Product.h"
#include "models/Item.h"

using namespace std;

int main()
{
    VendingMachine machine(IdleState::getInstance());

    machine.getInventory()->addItem(new Item(1, new Product("Coke", 10)));
    machine.getInventory()->addItem(new Item(2, new Product("Pepsi", 12)));
    machine.getInventory()->addItem(new Item(3, new Product("Chips", 15)));

    machine.insertCoin(20);
    machine.selectProduct(2);
    return 0;
}