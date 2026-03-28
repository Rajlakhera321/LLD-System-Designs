#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int currentId;
    static int generateId()
    {
        return currentId++;
    }
};

int IdGenerator::currentId = 0;