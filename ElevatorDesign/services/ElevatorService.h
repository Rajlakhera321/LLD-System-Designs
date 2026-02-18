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
        Elevator *e = scheduler->assign(req, repo.getAllElevator());

        if (req.getFloor() > e->getFloor()->floorNo)
            e->getUpQueue().push(req.getFloor());
        else
            e->getDownQueue().push(req.getFloor());

        if (e->getDirectionType() == Direction::IDLE)
        {
            Direction d = (req.getFloor() > e->getFloor()->floorNo)
                              ? Direction::UP
                              : Direction::DOWN;
            e->setDirectionType(d);
        }
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
        if (e->getDirectionType() == Direction::UP &&
            !e->getUpQueue().empty())
        {
            int nxt = e->getUpQueue().top();
            e->getUpQueue().pop();
            e->getFloor()->floorNo = nxt;

            std::cout << "Elevator " << e->getId()
                      << " moved to floor " << nxt << "\n";
        }
        else if (e->getDirectionType() == Direction::DOWN &&
                 !e->getDownQueue().empty())
        {
            int nxt = e->getDownQueue().top();
            e->getDownQueue().pop();
            e->getFloor()->floorNo = nxt;

            std::cout << "Elevator " << e->getId()
                      << " moved to floor " << nxt << "\n";
        }
        else
        {
            e->setDirectionType(Direction::IDLE);
        }
    }
};
