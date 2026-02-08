#pragma once
#include "../model/ParkingSpot.h"
#include "../service/DefaultParkingStrategy.h"

class ParkingSpotFactory
{
public:
    static std::unique_ptr<IParkingSpot> create(
        int id, ParkingSpotType type, IParkingStrategy *s)
    {
        return std::make_unique<ParkingSpot>(id, type, s);
    }
};