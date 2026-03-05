#include <iostream>

#include "services/ATMService.h"
#include "states/IdleState.h"
#include "models/Card.h"
#include "models/Account.h"

int main()
{
    Account *account = new Account("101010", 1000, nullptr);

    Card *card = new Card(1234, account);

    ATM *atm = new ATM(new IdleState(), 5000);

    atm->setCard(card);

    atm->insertCard();

    atm->enterPIN(1234);

    atm->balance();

    atm->withdraw(200);

    atm->balance();

    atm->eject();

    return 0;
}