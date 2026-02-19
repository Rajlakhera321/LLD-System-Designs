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
    Elevator(int startFloor = 0)
        : id(IdGenerator::generateElevatorId()),
          floor(new Floor(startFloor)),
          dir(Direction::IDLE),
          door(new Door())
    {
    }

    Floor *getFloor() const { return floor; }
    Direction getDirectionType() const { return dir; }
    Door *getDoor() const { return door; }

    void setDirectionType(Direction d) { dir = d; }

    auto &getUpQueue() { return upQueue; }
    auto &getDownQueue() { return downQueue; }

    int getId() const { return id; }
};