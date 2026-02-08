#pragma once
#include "../interfaces/IParkingStrategy.h"

class DefaultParkingStrategy : public IParkingStrategy
{
public:
    bool canPark(ParkingSpotType spot, VehicleType vehicle) const override
    {
        if (spot == ParkingSpotType::CAR && vehicle == VehicleType::CAR)
            return true;
        if (spot == ParkingSpotType::TRUCK && vehicle == VehicleType::TRUCK)
            return true;
        if (spot == ParkingSpotType::MOTORCYCLE && vehicle == VehicleType::MOTORCYCLE)
            return true;

        return false;
    }
};