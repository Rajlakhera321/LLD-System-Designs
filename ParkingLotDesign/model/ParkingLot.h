#pragma once
#include <vector>
#include <memory>
#include "ParkingFloor.h"

class ParkingLot
{
private:
    static ParkingLot *instance;
    std::vector<std::unique_ptr<ParkingFloor>> floors;

    ParkingLot() {}

public:
    static ParkingLot *getInstance()
    {
        if (instance == NULL)
        {
            instance = new ParkingLot();
        }
        return instance;
    }
    void addFloor(std::unique_ptr<ParkingFloor> f)
    {
        floors.push_back(std::move(f));
    }

    IParkingSpot *findSpot(const IVehicle &vehicle) const
    {
        for (const auto &floor : floors)
        {
            IParkingSpot *spot = floor->findAvailableSpot(vehicle);
            if (spot != NULL)
            {
                return spot;
            }
        }
        return NULL;
    }
};
