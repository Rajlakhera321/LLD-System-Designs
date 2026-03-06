#include <iostream>

#include "states/IdleState.h"
#include "states/ReadyState.h"
#include "states/DispenseState.h"
#include "models/VendingMachine.h"
#include "models/Product.h"
#include "models/Item.h"

using namespace std;

int main()
{
    IdleState idle;

    VendingMachine machine(&idle);

    machine.getInventory()->addItem(new Item(1, new Product("Coke", 10)));
    machine.getInventory()->addItem(new Item(2, new Product("Pepsi", 12)));
    machine.getInventory()->addItem(new Item(3, new Product("Chips", 15)));

    machine.insertCoin(20);
    machine.selectProduct(1);

    return 0;
}