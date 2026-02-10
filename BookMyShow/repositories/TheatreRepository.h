#pragma once
#include <bits/stdc++.h>
#include "../models/Theatre.h"

using namespace std;

class TheatreRepository
{
private:
    vector<Theatre *> theatres;

public:
    void addTheatre(Theatre *t)
    {
        theatres.push_back(t);
    }

    Theatre *findById(int id)
    {
        for (auto t : theatres)
            if (t->getThreatreId() == id)
                return t;
        return nullptr;
    }

    vector<Theatre *> findByName(string name)
    {
        vector<Theatre *> result;
        for (auto t : theatres)
            if (t->getThreatreName() == name)
                result.push_back(t);
        return result;
    }

    vector<Theatre *> findAll()
    {
        return theatres;
    }
};
