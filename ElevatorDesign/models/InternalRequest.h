#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class InternalRequest
{
private:
public:
    int destinationFloor;

    InternalRequest(int floor) : destinationFloor(floor) {}

    int getInternalFloor() const
    {
        return destinationFloor;
    }
};