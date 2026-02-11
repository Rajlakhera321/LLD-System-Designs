#pragma once
#include <bits/stdc++.h>
#include "Movie.h"
#include "ShowSeat.h"
#include "IdGenerator.h"

using namespace std;

class Show
{
private:
    int showId;
    Movie *movie;
    string startTime;
    string endTime;
    vector<ShowSeat *> showSeat;

public:
    Show(Movie *movie, string &st, string &et) : movie(movie), startTime(st), endTime(et)
    {
        showId = IdGenerator::generateShowId();
        showSeat = {};
    }

    int getShowId() const { return showId; }

    Movie *getMovie() const { return movie; }

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