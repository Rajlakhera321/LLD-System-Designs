#pragma once
#include <bits/stdc++.h>
#include "Movie.h"
#include "Show.h"
#include "User.h"
#include "../enums/BookingStatus.h"
#include "IdGenerator.h"

using namespace std;

class Booking
{
private:
    int bookingId;
    User *user;
    Show *show;
    Movie *movie;
    vector<ShowSeat *> seats;
    int amount;
    BookingStatus status;
    string createdAt;

public:
    Booking(User *user, Show *show, vector<ShowSeat *> seats, Movie *movie, int amount, string createdAt)
    {
        status = BookingStatus::CONFIRMED;
        bookingId = IdGenerator::generateBookingId();
    }
};