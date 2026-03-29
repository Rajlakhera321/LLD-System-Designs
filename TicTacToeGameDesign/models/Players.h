#pragma once
#include <bits/stdc++.h>
#include "../enums/Symbol.h"

using namespace std;

class Players
{
private:
    string name;
    Symbol symbol;

public:
    Players(string name, Symbol symbol) : name(name), symbol(symbol) {}

    string getName() const
    {
        return name;
    }

    Symbol getSymbol() const
    {
        return symbol;
    }
};