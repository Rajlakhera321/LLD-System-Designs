#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/Scheduler.h"

using namespace std;

class LookScheduler : public IScheduler
{
    Elevator *assign(const ExternalRequest &req, std::vector<Elevator *> &elevators) override
    {
        Elevator *best = nullptr;
        int bestScore = 1e9;

        for (auto &e : elevators)
        {
            int score = abs(req.getFloor() - e->getFloor()->floorNo);

            if (e->getDirectionType() == req.getDirection())
                score -= 7;

            if (score < bestScore)
            {
                bestScore = score;
                best = e;
            }
        }

        return best;
    }
};