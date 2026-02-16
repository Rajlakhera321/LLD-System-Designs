#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/Scheduler.h"

using namespace std;

class NearestScheduler : public IScheduler
{
    Elevator *assign(const ExternalRequest &req, std::vector<Elevator *> &elevators) override
    {
        return elevators[req.getFloor() % elevators.size()];
    }
};