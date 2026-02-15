#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class InternalRequest
{
public:
    int destinationFloor;

private:
    InternalRequest(int floor) : destinationFloor(floor) {}
};