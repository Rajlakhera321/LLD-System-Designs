#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class Movie
{
private:
    int movieId;
    string title;
    string description;
    string language;
    string releaseDate;
    string duration;

private:
    Movie(string title, string desc, string lang, string rd, string dur)
    {
        this->title = title;
        this->description = desc;
        this->language = lang;
        this->releaseDate = rd;
        this->duration = dur;
        movieId = IdGenerator::generateMovieId();
    }

    string getTitle() const { return title; }
    int getMovieId() const { return movieId; }
    string getReleaseDate() const { return releaseDate; }
    string getLanguage() const { return language; }
    string getDescription() const { return description; }
    string getDuration() const { return duration; }
};