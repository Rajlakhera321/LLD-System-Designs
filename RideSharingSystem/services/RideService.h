#pragma once
#include <bits/stdc++.h>
#include "../repositories/UserRepository.h"
#include "../repositories/DriverRepository.h"
#include "../repositories/VehicleRepository.h"
#include "../repositories/RideRepository.h"
#include "../repositories/RiderRepository.h"
#include "../interfaces/IFareInterface.h"
#include "../factories/FareFactory.h"
#include "../interfaces/IDriverMatchingInterface.h"
#include "../factories/DriverMatchingFactory.h"
#include "LocationService.h"
#include "../enums/PaymentStatus.h"
#include "PaymentService.h"
#include "../models/Payment.h"

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

    Ride *requestRide(Rider *rider, Location src, Location dest)
    {
        cout << "Ride requested by: " << rider->getName() << " from (" << src.getLat() << ", " << src.getLng() << ") to (" << dest.getLat() << ", " << dest.getLng() << ")" << endl;
        Ride *ride = new Ride(nullptr, rider, src, dest, nullptr, RideStatus::REQUESTED);
        rideRepo->addRide(ride);
        return ride;
    }

    Driver *assignDriver(Ride *ride)
    {
        auto available = driverRepo->getAvailableDrivers();
        cout << "Available drivers: " << available.size() << endl;

        IDriverMatchingInterface *matcher = DriverMatchingFactory::createDriverMatchingStrategy("NearestDriver");

        if (!matcher)
        {
            cout << "No driver matching strategy found!" << endl;
            return nullptr;
        }

        cout << "Driver matching strategy created: " << (matcher ? "Yes" : "No") << endl;
        Driver *driver = matcher->findMatchingDrivers(available, ride->getSrc());
        cout << "Driver found: " << (driver ? driver->getName() : "None") << endl;

        if (driver)
        {
            cout << "Assigning driver: " << driver->getName() << " to ride ID: " << ride->getId() << endl;
            driver->setStatus(DriverStatus::BUSY);
            ride->assignDriver(driver);
            cout << "Driver assigned: " << (driver ? driver->getName() : "None") << " for ride ID: " << ride->getId() << endl;
        }

        delete matcher;
        return driver;
    }

    void startRide(Ride *r) { r->start(); }
    void endRide(Ride *r) { r->finish(); }

    void calculateFare(LocationService *locationService, Ride *r, bool surge)
    {
        IFareInterface *strategy = FareFactory::getStrategy(surge);
        r->setFare(strategy->calculateFare(locationService, r->getSrc(), r->getDest()));
        delete strategy;
    }

    Payment *completeRide(RideService *rideService, PaymentService *paymentService, LocationService *locationService, Ride *r, bool surge)
    {
        rideService->startRide(r);
        rideService->calculateFare(locationService, r, surge);
        rideService->endRide(r);

        User *user = userRepo->getUserById(r->getRider()->getId());

        Payment *p = new Payment(200.00, "Credit Card", PaymentStatus::PENDING, user);
        paymentService->addPayment(p);
        paymentService->updatePaymentStatus(p->getPaymentId(), PaymentStatus::PAID);
        cout << "Payment completed for ride ID: " << r->getId() << " with amount: " << p->getAmount() << endl;
        return p;
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