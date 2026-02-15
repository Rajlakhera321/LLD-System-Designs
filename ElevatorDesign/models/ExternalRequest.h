#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class ExternalRequest
{
public:
    int floor;
    Direction directionType;

private:
    ExternalRequest(int floor, Direction dir) : floor(floor), directionType(dir) {}
};