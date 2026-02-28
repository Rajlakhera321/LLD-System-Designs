#pragma once
#include "../models/Location.h"
#include "../services/LocationService.h"

class IFareInterface
{
public:
    virtual double calculateFare(LocationService *locationService, Location src, Location dest) = 0;
    virtual ~IFareInterface() {}
};