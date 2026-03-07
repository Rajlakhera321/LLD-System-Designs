#pragma once
#include "../interfaces/IState.h"

class ReadyState : public IState
{
private:
    static ReadyState *instance;

public:
    static ReadyState *getInstance();

    void insertCoin(VendingMachine *, int) override;
    void selectProduct(VendingMachine *, int) override;
    void dispense(VendingMachine *) override;
    void cancel(VendingMachine *) override;
};