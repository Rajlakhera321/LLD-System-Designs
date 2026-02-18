#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/Scheduler.h"

using namespace std;

class FcfsScheduler : public IScheduler
{
public:
    Elevator *assign(const ExternalRequest &req, vector<Elevator *> &elevators) override
    {
        return elevators[req.getFloor() % elevators.size()];
    }
};