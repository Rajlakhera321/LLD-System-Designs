#pragma once
#include <bits/stdc++.h>
#include "Movie.h"
#include "ShowSeat.h"

using namespace std;

class Show
{
private:
    int showId;
    Movie *movie;
    string startTime;
    string endTime;
    vector<ShowSeat *> showSeat;
};