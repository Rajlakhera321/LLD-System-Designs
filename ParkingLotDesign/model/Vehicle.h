#pragma once
#include "../interfaces/IVehicle.h"

class Vehicle : public IVehicle
{
private:
    int reg;
    VehicleType type;

public:
    Vehicle(int r, VehicleType t) : reg(r), type(t) {}

    VehicleType getType() const override { return type; }
    int getRegNumber() const override { return reg; }
};
