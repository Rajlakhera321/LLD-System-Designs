#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class ExternalRequest
{
private:
    int floor;
    Direction directionType;

public:
    ExternalRequest(int floor, Direction dir) : floor(floor), directionType(dir) {}

    int getFloor() const { return floor; }

    Direction getDirection() const { return directionType; }
};