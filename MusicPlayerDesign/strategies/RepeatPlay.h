#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPlayStrategy.h"
#include "../playList/PlayList.h"
#include "../models/Song.h"

class RepeatPlay : public IPlayStrategy
{
public:
    Song *next(PlayList *playlist) override
    {
        std::cout << "Playing songs in repeat mode." << std::endl;
        return playlist->getCurrentSong();
    }

    Song *prev(PlayList *playlist) override
    {
        std::cout << "Playing songs in repeat mode." << std::endl;
        return playlist->getCurrentSong();
    }
};