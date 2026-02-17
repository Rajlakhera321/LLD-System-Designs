#pragma once
#include <bits/stdc++.h>
#include "../enums/Direction.enum.h"
#include "Door.h"
#include "IdGenerator.h"
#include "Floor.h"

using namespace std;

class Elevator
{
private:
    int id;
    Floor *floor;
    Direction dir;
    Door *door;

    priority_queue<int, vector<int>, greater<>> upQueue;
    priority_queue<int> downQueue;

public:
    Elevator() : floor(0), dir(Direction::IDLE)
    {
        id = IdGenerator::generateElevatorId();
    }

    Floor *getFloor() const
    {
        return floor;
    }

    Direction getDirectionType() const
    {
        dir;
    }

    auto getUpQueue() const { return upQueue; }

    auto getDownQueue() const { return downQueue; }

    int getId() const { return id; }
};