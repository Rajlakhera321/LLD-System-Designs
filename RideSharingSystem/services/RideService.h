#pragma once
#include <bits/stdc++.h>
#include "repositories/UserRepository.h"
#include "repositories/DriverRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RideRepository.h"
#include "repositories/RiderRepository.h"

using namespace std;

class RideService
{
private:
    UserRepository *userRepo;
    DriverRepository *driverRepo;
    VehicleRepository *vehicleRepo;
    RideRepository *rideRepo;
    RiderRepository *riderRepo;

public:
    RideService(UserRepository *userRepo, DriverRepository *driverRepo, VehicleRepository *vehicleRepo, RideRepository *rideRepo, RiderRepository *riderRepo)
        : userRepo(userRepo), driverRepo(driverRepo), vehicleRepo(vehicleRepo), rideRepo(rideRepo), riderRepo(riderRepo) {}

    void bookRide(int riderId, int driverId, const Location &pickupLocation, const Location &dropLocation)
    {
        Rider *rider = riderRepo->getRiderById(riderId);
        Driver *driver = driverRepo->getDriverById(driverId);
        if (rider && driver)
        {
            Vehicle *vehicle = vehicleRepo->getVehicleByDriverName(driver->getName());
            if (vehicle)
            {
                Ride *ride = new Ride(driver, rider, pickupLocation, dropLocation, vehicle, RideStatus::REQUESTED);
                rideRepo->addRide(ride);
            }
        }
    }

    Ride *getRideById(int rideId)
    {
        return rideRepo->getRideById(rideId);
    }

    vector<Ride *> getRidesByUserId(int userId)
    {
        return rideRepo->getRidesByUserId(userId);
    }

    vector<Ride *> getRidesByDriverId(int driverId)
    {
        return rideRepo->getRidesByDriverId(driverId);
    }
};