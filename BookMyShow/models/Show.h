#pragma once
#include <bits/stdc++.h>
#include "Movie.h"
#include "ShowSeat.h"
#include "IdGenerator.h"
#include "Theatre.h"

using namespace std;

class Show
{
private:
    int showId;
    Movie *movie;
    Theatre *theatre;
    string date;
    string startTime;
    string endTime;
    vector<ShowSeat *> showSeat;

public:
    Show(Movie *movie, Theatre *th, string &st, string &et, string &date) : movie(movie), theatre(th), startTime(st), endTime(et), date(date)
    {
        showId = IdGenerator::generateShowId();
        showSeat = {};
    }

    int getShowId() const { return showId; }

    Movie *getMovie() const { return movie; }

    Theatre *getTheatre() const { return theatre; }

    string getShowDate() const { return date; }

    string getStartTime() const { return startTime; }

    void addShowSeat(ShowSeat *show)
    {
        showSeat.push_back(show);
    }

    vector<ShowSeat *> getShowSeats() const
    {
        return showSeat;
    }
};