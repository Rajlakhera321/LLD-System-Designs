#pragma once
#include "../enum/VehicleType.h"

class IVehicle
{
public:
    virtual VehicleType getType() const = 0;
    virtual int getRegNumber() const = 0;
    virtual ~IVehicle() = default;
};