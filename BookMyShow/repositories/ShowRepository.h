#pragma once
#include <bits/stdc++.h>
#include "../models/Show.h"

using namespace std;

class ShowRepository
{
private:
    vector<Show *> shows;

public:
    void addShow(Show *s)
    {
        shows.push_back(s);
    }

    Show *findById(int id)
    {
        for (auto s : shows)
            if (s->getShowId() == id)
                return s;
        return nullptr;
    }

    vector<Show *> findShowsByMovie(Movie *movie)
    {
        vector<Show *> result;
        for (auto s : shows)
            if (s->getMovie()->getMovieId() == movie->getMovieId())
                result.push_back(s);
        return result;
    }

    vector<Show *> findShowsStartingAt(string start)
    {
        vector<Show *> result;
        for (auto s : shows)
            if (s->getStartTime() == start)
                result.push_back(s);
        return result;
    }

    vector<Show *> findAll()
    {
        return shows;
    }
};
