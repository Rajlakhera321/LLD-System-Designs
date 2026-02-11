#pragma once
#include <bits/stdc++.h>
#include "../models/Theatre.h"
#include "../repositories/TheatreRepository.h"

using namespace std;

class TheatreService
{
private:
    TheatreRepository *theatreRepo;

public:
    TheatreService(TheatreRepository *repo) : theatreRepo(repo) {}

    Theatre *createTheatre(string name, string address)
    {
        Theatre *t = new Theatre(name, address);
        theatreRepo->addTheatre(t);
        return t;
    }

    Theatre *getTheatreById(int id)
    {
        return theatreRepo->findById(id);
    }

    vector<Theatre *> findTheatresByName(string name)
    {
        return theatreRepo->findByName(name);
    }

    vector<Theatre *> getAllTheatres()
    {
        return theatreRepo->findAll();
    }
};