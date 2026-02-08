#pragma once
#include "../interfaces/IVehicle.h"
#include "../enum/ParkingSpotType.h"

class IParkingSpot
{
public:
    virtual bool canPark(const IVehicle &vehicle) const = 0;
    virtual void parkVehicle(IVehicle *vehicle) = 0;
    virtual void removeVehicle() = 0;
    virtual bool isFree() const = 0;
    virtual int getId() const = 0;
    virtual ~IParkingSpot() = default;
};