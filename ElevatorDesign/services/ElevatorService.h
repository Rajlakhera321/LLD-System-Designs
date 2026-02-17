#pragma once
#include <bits/stdc++.h>
#include "../repositories/ElevatorRepository.h"
#include "../interfaces/Scheduler.h"
#include "../enums/Scheduler.enum.h"
#include "../factories/SchedulerFactory.h"

class ElevatorService
{
private:
    ElevatorRepository repo;
    IScheduler *scheduler;

public:
    ElevatorService(int count, SchedulerType type)
        : repo(count), scheduler(SchedulerFactory::create(type)) {}

    void handleExternal(const ExternalRequest &req)
    {
        Elevator *e = scheduler->assign(req, repo->getAllElevator());
        e->getUpQueue().push(req.getFloor());
        if (e->getDirectionType() == Direction::IDLE)
            e->getDirectionType() = (req.getFloor() > e->getFloor()->floorNo)
                                        ? Direction::UP
                                        : Direction::DOWN;
    }

    void step()
    {
        for (auto *e : repo.getAllElevator())
        {
            moveElevator(e);
        }
    }

private:
    void moveElevator(Elevator *e)
    {
        if (e->getDirectionType() == Direction::UP && !e->getUpQueue().empty())
        {
            int nxt = e->getUpQueue().top();
            e->getUpQueue().pop();
            std::cout << "Elevator " << e->getId()
                      << " moving to " << nxt << "\n";
            e->getFloor()->floorNo = nxt;
        }
        else if (e->getDirectionType() == Direction::DOWN && !e->getDownQueue().empty())
        {
            int nxt = e->getDownQueue().top();
            e->getDownQueue().pop();
            std::cout << "Elevator " << e->getId()
                      << " moving to " << nxt << "\n";
            e->getFloor()->floorNo = nxt;
        }
    }
};
