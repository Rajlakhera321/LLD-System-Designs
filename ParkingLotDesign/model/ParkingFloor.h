#pragma once
#include <vector>
#include <memory>
#include "ParkingSpot.h"

class ParkingFloor
{
private:
    int floorNo;
    std::vector<std::unique_ptr<IParkingSpot>> parkingSpots;

public:
    ParkingFloor(int floorNumber) : floorNo(floorNumber) {}

    void addSpot(std::unique_ptr<IParkingSpot> spot)
    {
        parkingSpots.push_back(std::move(spot));
    }

    IParkingSpot *findAvailableSpot(const IVehicle &vehicle) const
    {
        for (auto &spot : parkingSpots)
        {
            if (spot->isFree() && spot->canPark(vehicle))
            {
                return spot.get();
            }
        }
        return NULL;
    }
};
