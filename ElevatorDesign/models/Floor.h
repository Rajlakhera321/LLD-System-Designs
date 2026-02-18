#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class Floor
{
public:
    int floorNo;
    Floor(int floor) : floorNo(floor) {}

    int getFloor() const
    {
        return floorNo;
    }
};