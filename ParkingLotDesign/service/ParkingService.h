#pragma once
#include "../model/ParkingLot.h"
#include "SimpleTicketGenerator.h"

class ParkingService
{
private:
    SimpleTicketGenerator ticketGen;

public:
    std::unique_ptr<Ticket> parkVehicle(IVehicle &vehicle)
    {
        ParkingLot *lot = ParkingLot::getInstance();

        IParkingSpot *spot = lot->findSpot(vehicle);

        if (!spot)
            throw std::runtime_error("No available parking spots");

        spot->parkVehicle(&vehicle);
        return ticketGen.create(&vehicle, spot);
    }
};
