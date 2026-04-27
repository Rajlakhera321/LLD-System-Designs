#pragma once
#include <bits/stdc++.h>

using namespace std;

class Song
{
private:
    string name;
    string artist;
    int duration; // in seconds

public:
    Song(string name, string artist, int duration) : name(name), artist(artist), duration(duration) {};

    string getName() const;
    string getArtist() const;
    int getDuration() const;
};