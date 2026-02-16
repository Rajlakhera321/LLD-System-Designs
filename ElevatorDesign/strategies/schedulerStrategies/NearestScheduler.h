#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/Scheduler.h"

using namespace std;

class NearestScheduler : public IScheduler
{
    Elevator *assign(const ExternalRequest &req, std::vector<Elevator *> &elevators) override
    {
        int bestDist = INT_MAX;
        Elevator *best;

        for (auto &e : elevators)
        {
            int d = abs(req.getFloor() - e->getFloor()->floorNo);
            if (d < bestDist)
            {
                bestDist = d;
                best = e;
            }
        }

        return best;
    }
};