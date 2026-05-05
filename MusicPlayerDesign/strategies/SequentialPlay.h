#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPlayStrategy.h"
#include "../playList/PlayList.h"

using namespace std;

class SequentialPlay : public IPlayStrategy
{
public:
    Song *next(PlayList *playlist) override
    {
        std::cout << "Playing next song in sequential mode." << std::endl;
        return playlist->playNext();
    }

    Song *prev(PlayList *playlist) override
    {
        std::cout << "Playing previous song in sequential mode." << std::endl;
        return playlist->playPrevious();
    }
};