#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/Scheduler.h"

using namespace std;

class ScanScheduler : public IScheduler
{
public:
    Elevator *assign(const ExternalRequest &req, std::vector<Elevator *> &elevators) override
    {
        Elevator *best = nullptr;
        int bestScore = 1e9;

        for (auto &e : elevators)
        {
            int score = abs(req.getFloor() - e->getFloor()->getFloor());

            if (e->getDirectionType() == req.getDirection())
                score -= 5;

            if (score < bestScore)
            {
                bestScore = score;
                best = e;
            }
        }

        return best;
    }
};