#pragma once
#include "../interfaces/ITicketGenerator.h"

class SimpleTicketGenerator : public ITicketGenerator
{
private:
    int counter = 0;

public:
    std::unique_ptr<Ticket> create(IVehicle *v, IParkingSpot *spot) override
    {
        return std::make_unique<Ticket>(
            ++counter,
            v->getRegNumber(),
            spot->getId());
    }
};
