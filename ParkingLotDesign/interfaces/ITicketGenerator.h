#pragma once
#include "../model/Ticket.h"
#include "../interfaces/IVehicle.h"
#include "../interfaces/IParkingSpot.h"

class ITicketGenerator
{
public:
    virtual std::unique_ptr<Ticket> create(IVehicle *vehicle, IParkingSpot *spot) = 0;
    virtual ~ITicketGenerator() = default;
};