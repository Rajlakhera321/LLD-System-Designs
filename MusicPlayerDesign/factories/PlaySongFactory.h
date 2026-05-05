#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IPlayStrategy.h"
#include "../strategies/SequentialPlay.h"
#include "../strategies/ShufflePlay.h"
#include "../strategies/RepeatPlay.h"

using namespace std;

class PlaySongFactory
{
public:
    static std::unique_ptr<IPlayStrategy>
    createPlayStrategy(const std::string &type)
    {
        if (type == "sequential")
        {
            return std::make_unique<SequentialPlay>();
        }
        else if (type == "shuffle")
        {
            return std::make_unique<ShufflePlay>();
        }
        else if (type == "repeat")
        {
            return std::make_unique<RepeatPlay>();
        }

        throw std::invalid_argument("Invalid play strategy type");
    }
};