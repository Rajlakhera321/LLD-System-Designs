#pragma once
#include <bits/stdc++.h>
#include "../models/Elevator.h"
#include "../models/ExternalRequest.h"

class IScheduler
{
public:
    virtual Elevator *assign(const ExternalRequest &req, std::vector<Elevator *> &elevators) = 0;
    virtual ~IScheduler() = default;
};