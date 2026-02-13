#pragma once
#include <bits/stdc++.h>
#include "../models/Show.h"
#include "../repositories/ShowRepository.h"
#include "../repositories/SeatRepository.h"
#include "../models/ShowSeat.h"
#include "../enums/SeatStatus.h"

using namespace std;

class ShowService
{
private:
    ShowRepository *showRepo;
    SeatRepository *seatRepo;

public:
    ShowService(ShowRepository *sRepo, SeatRepository *seatRepo)
        : showRepo(sRepo), seatRepo(seatRepo) {}

    Show *createShow(Movie *movie, Theatre *theatre, string start, string end, string showDate)
    {
        Show *show = new Show(movie, theatre, start, end, showDate);
        showRepo->addShow(show);
        return show;
    }

    /// Create ShowSeat for each seat in the theatre
    void generateShowSeats(Show *show, vector<Seat *> theatreSeats, int basePrice)
    {
        for (Seat *s : theatreSeats)
        {
            ShowSeat *ss = new ShowSeat(s, basePrice);
            show->addShowSeat(ss);
        }
    }

    vector<ShowSeat *> getAvailableSeats(Show *show)
    {
        vector<ShowSeat *> result;
        for (auto ss : show->getShowSeats())
        {
            if (ss->getStatus() == SeatStatus::AVAILABLE)
                result.push_back(ss);
        }
        return result;
    }

    bool blockSeat(ShowSeat *seat)
    {
        if (seat->getStatus() != SeatStatus::AVAILABLE)
            return false;

        seat->setStatus(SeatStatus::BLOCKED);
        return true;
    }

    void confirmSeat(ShowSeat *seat)
    {
        seat->setStatus(SeatStatus::BOOKED);
    }
};