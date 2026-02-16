#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int elevatorId;

    static int generateElevatorId() { return ++elevatorId; }
};

int IdGenerator::elevatorId = 0;
