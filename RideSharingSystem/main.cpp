#include <bits/stdc++.h>
#include "services/UserService.h"
#include "services/DriverService.h"
#include "services/VehicleService.h"
#include "services/LocationService.h"
#include "services/RideService.h"
#include "services/RiderService.h"
#include "services/PaymentService.h"
#include "interfaces/IPaymentInterface.h"
#include "strategies/paymentStrategy/Stripe.h"
#include "factories/PaymentFactory.h"

using namespace std;

int main()
{
    // Initialize services and repositories
    UserService *userService;
    DriverService *driverService;
    VehicleService *vehicleService;
    LocationService *locationService;
    RideService *rideService;
    RiderService *riderService;
    PaymentService *paymentService;
    PaymentFactory *paymentFactory;

    // Initialize repositories
    UserRepository *userRepo = new UserRepository();
    DriverRepository *driverRepo = new DriverRepository();
    VehicleRepository *vehicleRepo = new VehicleRepository();
    LocationRepository *locationRepo = new LocationRepository();
    RideRepository *rideRepo = new RideRepository();
    RiderRepository *riderRepo = new RiderRepository();
    PaymentRepository *paymentRepo = new PaymentRepository();
    paymentService = new PaymentService(paymentRepo);

    // Create payment processor using factory
    IPaymentInterface *stripePayment = PaymentFactory::createPaymentProcessor("Stripe", paymentService, riderRepo);

    // Initialize services
    userService = new UserService(userRepo);
    driverService = new DriverService(driverRepo);
    vehicleService = new VehicleService(vehicleRepo, driverRepo);
    locationService = LocationService::getInstance();
    rideService = new RideService(userRepo, driverRepo, vehicleRepo, rideRepo, riderRepo);
    riderService = new RiderService(riderRepo);

    // Sample data and operations

    // Adding users
    userService->registerUser("Alice", "1234567890");
    userService->registerUser("Bob", "0987654321");

    // Adding drivers and vehicles
    driverService->addDriver("Charlie", "1112223333", "DL12345");
    driverService->addDriver("Dave", "4445556666", "DL67890");

    driverService->setLocationForDriver(driverService->getDriverById(3), 12.9716, 77.5946); // Charlie in Bangalore
    driverService->setLocationForDriver(driverService->getDriverById(4), 13.0827, 80.2707); // Dave in Chennai

    // Adding vehicles for drivers
    vehicleService->addVehicle(driverService->getDriverById(3), "KA01AB1234", "Red", "Swift");
    vehicleService->addVehicle(driverService->getDriverById(4), "KA01CD5678", "Blue", "Baleno");

    // Adding locations
    locationService->addLocation(12.9716, 77.5946); // Bangalore
    locationService->addLocation(13.0827, 80.2707); // Chennai

    // Adding riders
    riderService->addRider("Eve", "5556667777");

    // Book a ride for Eve with Charlie
    rideService->requestRide(riderService->getRiderById(5), Location(12.9716, 77.5946), Location(13.0827, 80.2707));

    Driver *assigned = rideService->assignDriver(rideService->getRideById(1));
    std::cout << "Assigned driver: " << assigned->getName() << std::endl;

    // Process payment for the ride
    Payment *payment = rideService->completeRide(rideService, paymentService, locationService, rideService->getRideById(1), false);
    std::cout << "Final fare: " << payment->getAmount() << std::endl;
    return 0;
}