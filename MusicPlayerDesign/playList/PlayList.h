#pragma once
#include <bits/stdc++.h>
#include "../models/Song.h"

using namespace std;

class PlayList
{
private:
    vector<Song> songs;
    int currentIndex;

public:
    PlayList() : currentIndex(0) {};

    void addSong(const Song &song);

    void removeSong(const string &songName);

    Song *getCurrentSong();

    Song *playNext();

    Song *playPrevious();
};