#include <iostream>
#include "model/ParkingLot.h"
#include "service/ParkingService.h"
#include "factory/ParkingSpotFactory.h"
#include "model/Vehicle.h"
#include "service/DefaultParkingStrategy.h"

ParkingLot *ParkingLot::instance = NULL;

int main()
{
    auto lot = ParkingLot::getInstance();
    DefaultParkingStrategy strategy;

    auto floor = std::make_unique<ParkingFloor>(1);

    floor->addSpot(ParkingSpotFactory::create(1, ParkingSpotType::CAR, &strategy));
    floor->addSpot(ParkingSpotFactory::create(2, ParkingSpotType::TRUCK, &strategy));

    lot->addFloor(std::move(floor));

    Vehicle v1(101, VehicleType::CAR);

    ParkingService service;

    try
    {
        auto ticket = service.parkVehicle(v1);
        std::cout << "Parked successfully! Ticket #"
                  << ticket->getTicketNumber() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
};