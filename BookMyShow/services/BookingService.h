#pragma once
#include <bits/stdc++.h>
#include "../repositories/BookingRepository.h"
#include "../services/PaymentService.h"
#include "../services/ShowService.h"

using namespace std;

class BookingService
{
private:
    BookingRepository *bookingRepo;
    ShowService *showService;
    PaymentService *paymentService;

public:
    BookingService(
        BookingRepository *bRepo,
        ShowService *sService,
        PaymentService *pService)
        : bookingRepo(bRepo), showService(sService), paymentService(pService) {}

    Booking *createBooking(User *user, Show *show, vector<ShowSeat *> seats, string paymentType)
    {
        int totalAmount = 0;

        // Step 1: Block seats
        for (auto seat : seats)
        {
            if (!showService->blockSeat(seat))
            {
                cout << "Seat already booked!" << endl;
                return nullptr;
            }
            totalAmount += seat->getPrice();
        }

        // Step 2: Process payment
        if (!paymentService->processPayment(user, totalAmount, paymentType))
        {
            cout << "Payment failed!" << endl;
            return nullptr;
        }

        // Step 3: Convert BLOCKED -> BOOKED
        for (auto seat : seats)
            showService->confirmSeat(seat);

        // Step 4: Create Booking Object
        Booking *b = new Booking(user, show, seats, show->getMovie(), totalAmount, "today");
        bookingRepo->addBooking(b);

        return b;
    }
};