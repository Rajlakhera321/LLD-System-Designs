#pragma once
#include <bits/stdc++.h>
#include "../models/Elevator.h"

using namespace std;

class ElevatorRepository
{
private:
    vector<Elevator *> elevators;

public:
    ElevatorRepository(int count)
    {
        for (int i = 0; i < count; i++)
            elevators.push_back(new Elevator());
    }

    vector<Elevator *> getAllElevator() const
    {
        return elevators;
    }

    Elevator *getById(int id)
    {
        return elevators[id];
    }
};