#pragma once
#include "bits/stdc++.h"

class IDGenerator
{
private:
    int id;

public:
    static int generateId()
    {
        return ++id;
    }
};

int IDGenerator::id = 0;