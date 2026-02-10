#pragma once
#include <bits/stdc++.h>
#include "../models/Seat.h"

using namespace std;

class ISeatInterface
{
public:
    virtual Seat *createSeat(string row) = 0;
};