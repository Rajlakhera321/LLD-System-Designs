#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IState.h"
#include "../models/VendingMachine.h"

using namespace std;

class DispenseState : public IState
{
private:
    static DispenseState *instance;

public:
    static DispenseState *getInstance();

    void insertCoin(VendingMachine *machine, int money) override;
    void selectProduct(VendingMachine *machine, int code) override;
    void dispense(VendingMachine *machine) override;
    void cancel(VendingMachine *machine) override;
};