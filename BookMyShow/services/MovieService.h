#pragma once
#include <bits/stdc++.h>
#include "../repositories/MovieRepository.h"

using namespace std;

class MovieService
{
private:
    MovieRepository *repo;

public:
    MovieService(MovieRepository *repo) : repo(repo) {}

    Movie *addMovie(string title, string desc, string lang, string rd, string dur)
    {
        Movie *m = new Movie(title, desc, lang, rd, dur);
        repo->addMovie(m);
        return m;
    }

    vector<Movie *> findByLanguage(string lang)
    {
        return repo->findByLanguage(lang);
    }

    vector<Movie *> getAllMovies()
    {
        return repo->findAll();
    }
};