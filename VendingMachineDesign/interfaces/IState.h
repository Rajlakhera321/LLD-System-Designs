#pragma once
#include <bits/stdc++.h>

using namespace std;

class VendingMachine;

class IState
{
public:
    virtual void insertCoin(VendingMachine *, int money) = 0;
    virtual void selectProduct(VendingMachine *, int code) = 0;
    virtual void dispense(VendingMachine *) = 0;
    virtual void cancel(VendingMachine *) = 0;
};