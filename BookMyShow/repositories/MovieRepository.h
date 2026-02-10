#pragma once
#include <bits/stdc++.h>
#include "../models/Movie.h"

using namespace std;

class MovieRepository
{
private:
    vector<Movie *> movies;

public:
    void addMovie(Movie *movie)
    {
        movies.push_back(movie);
    }

    Movie *findById(int id)
    {
        for (auto m : movies)
            if (m->getMovieId() == id)
                return m;
        return nullptr;
    }

    vector<Movie *> findByLanguage(string lang)
    {
        vector<Movie *> result;
        for (auto m : movies)
            if (m->getLanguage() == lang)
                result.push_back(m);
        return result;
    }

    vector<Movie *> findAll()
    {
        return movies;
    }
};
