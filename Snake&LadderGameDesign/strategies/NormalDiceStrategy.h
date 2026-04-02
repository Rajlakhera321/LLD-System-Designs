#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IDiceStrategy.h"

using namespace std;

using namespace std;

class NormalDiceStrategy : public IDiceStrategy
{
public:
    int roll()
    {
        return rand() % 6 + 1; // Simulate rolling a 6-sided die
    }
};