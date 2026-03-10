#include <iostream>
#include <vector>
#include <string>
#include "states/IdleState.h"
#include "models/VendingMachine.h"
#include "models/Product.h"
#include "models/Item.h"
#include "strategies/CoinStrategy.h"
#include "enums/Coin.h"

using namespace std;

int main()
{
    VendingMachine machine(IdleState::getInstance());

    machine.getInventory()->addItem(new Item(1, new Product("Coke", 10)));
    machine.getInventory()->addItem(new Item(2, new Product("Pepsi", 12)));
    machine.getInventory()->addItem(new Item(3, new Product("Chips", 15)));

    machine.setPaymentInterface(new CoinStrategy());

    machine.insertCoin(static_cast<int>(Coin::TWENTY));
    machine.selectProduct(1);

    return 0;
}