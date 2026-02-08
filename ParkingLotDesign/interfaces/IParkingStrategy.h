#pragma once
#include "../enum/VehicleType.h"
#include "../enum/ParkingSpotType.h"

class IParkingStrategy
{
public:
    virtual bool canPark(ParkingSpotType spotType, VehicleType vehicle) const = 0;
    virtual ~IParkingStrategy() = default;
};