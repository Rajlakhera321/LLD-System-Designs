#pragma once
#include <bits/stdc++.h>
#include "../models/Booking.h"

using namespace std;

class BookingRepository
{
private:
    vector<Booking *> bookings;

public:
    void addBooking(Booking *b) { bookings.push_back(b); }

    Booking *getBookingById(int id)
    {
        for (auto b : bookings)
        {
            if (b->getId() == id)
                return b;
        }
        return nullptr;
    }

    vector<Booking *> getAllBookings()
    {
        return bookings;
    }

    vector<Booking *> getBookingsByMovieId(int movieId)
    {
        vector<Booking *> booking;
        for (auto b : bookings)
        {
            if (b->getMovie()->getMovieId() == movieId)
                booking.push_back(b);
        }
        return booking;
    }

    vector<Booking *> getBookingsByShowId(int showId)
    {
        vector<Booking *> booking;
        for (auto b : bookings)
        {
            if (b->getShow()->getShowId() == showId)
                booking.push_back(b);
        }
        return booking;
    }
};