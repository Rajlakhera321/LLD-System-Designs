#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int userId;
    static int movieId;
    static int seatId;
    static int theatreId;
    static int showSeatId;
    static int bookingId;
    static int showId;

    static int generateUserId() { return ++userId; }
    static int generateMovieId() { return ++movieId; }
    static int generateSeatId() { return ++seatId; }
    static int generateThreatreId() { return ++theatreId; }
    static int generateShowSeatId() { return ++showSeatId; }
    static int generateBookingId() { return ++bookingId; }
    static int generateShowId() { return ++showId; }
};

int IdGenerator::userId = 0;
int IdGenerator::movieId = 0;
int IdGenerator::seatId = 0;
int IdGenerator::theatreId = 0;
int IdGenerator::showSeatId = 0;
int IdGenerator::bookingId = 0;
int IdGenerator::showId = 0;