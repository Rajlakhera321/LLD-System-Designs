#pragma once
#include <bits/stdc++.h>

using namespace std;

class Product
{
private:
    string name;
    double price;

public:
    Product(const string &name, double price) : name(name), price(price) {}

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }
};