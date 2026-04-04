#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int playerId;

    static int getNextPlayerId()
    {
        return ++playerId;
    }
};

int IdGenerator::playerId = 0; // Initialize static member