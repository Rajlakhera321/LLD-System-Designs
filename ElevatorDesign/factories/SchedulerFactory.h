#pragma once
#include <bits/stdc++.h>
#include "../enums/Scheduler.enum.h"
#include "../interfaces/Scheduler.h"
#include "../strategies/schedulerStrategies/FcfsScheduler.h"
#include "../strategies/schedulerStrategies/LookScheduler.h"
#include "../strategies/schedulerStrategies/NearestScheduler.h"
#include "../strategies/schedulerStrategies/ScanScheduler.h"

class SchedulerFactory
{
public:
    static IScheduler *create(SchedulerType type)
    {
        switch (type)
        {
        case SchedulerType::NEAREST:
            return new NearestScheduler();
        case SchedulerType::SCAN:
            return new ScanScheduler();
        case SchedulerType::LOOK:
            return new LookScheduler();
        case SchedulerType::FCFS:
            return new FcfsScheduler();
        }
        return new NearestScheduler();
    }
};