#pragma once
#include <memory>
#include "../interfaces/IParkingSpot.h"
#include "../interfaces/IParkingStrategy.h"

class ParkingSpot : public IParkingSpot
{
private:
    int spotId;
    ParkingSpotType type;
    IVehicle *parkedVehicle;
    IParkingStrategy *strategy;

public:
    ParkingSpot(int id, ParkingSpotType type, IParkingStrategy *s)
        : spotId(id), type(type), strategy(s), parkedVehicle(nullptr) {}

    bool canPark(const IVehicle &vehicle) const override
    {
        return parkedVehicle == nullptr && strategy->canPark(type, vehicle.getType());
    }

    void parkVehicle(IVehicle *v) override
    {
        parkedVehicle = v;
    }

    bool isFree() const override
    {
        return parkedVehicle == nullptr;
    }

    void removeVehicle() override { parkedVehicle = nullptr; }

    int getId() const override
    {
        return spotId;
    }
};
