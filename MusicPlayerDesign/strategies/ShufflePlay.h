#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPlayStrategy.h"

using namespace std;

class ShufflePlay : public IPlayStrategy
{
public:
    Song *next(PlayList *playlist) override
    {
        std::cout << "Playing songs in shuffle mode." << std::endl;
        return playlist->getSong(rand() % playlist->getSongCount());
    }

    Song *prev(PlayList *playlist) override
    {
        std::cout << "Playing songs in shuffle mode." << std::endl;
        return playlist->getSong(rand() % playlist->getSongCount());
    }
};