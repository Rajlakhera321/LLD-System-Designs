#pragma once
#include <bits/stdc++.h>
#include "Product.h"

using namespace std;

class Item
{
private:
    int code;
    Product *product;
    bool isAvailable;

public:
    Item(int code, Product *product)
    {
        this->code = code;
        this->product = product;
        this->isAvailable = true;
    }

    int getCode()
    {
        return code;
    }

    Product *getProduct()
    {
        return product;
    }

    bool getAvailability()
    {
        return isAvailable;
    }

    void setAvailability(bool availability)
    {
        this->isAvailable = availability;
    }
};