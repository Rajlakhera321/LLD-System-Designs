#pragma once
#include "../interfaces/IState.h"

class IdleState : public IState
{
private:
    static IdleState *instance;

public:
    static IdleState *getInstance();

    void insertCoin(VendingMachine *, int) override;
    void selectProduct(VendingMachine *, int) override;
    void dispense(VendingMachine *) override;
    void cancel(VendingMachine *) override;
};