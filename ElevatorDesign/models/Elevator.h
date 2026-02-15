#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"

using namespace std;

class Elevator
{
public:
    int id;
    int currentFloor;
    Direction dir;
    bool doorOpen;

private:
    Elevator(int floor, Direction dir) {}
};