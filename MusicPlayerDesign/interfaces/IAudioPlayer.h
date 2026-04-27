#pragma once
#include <bits/stdc++.h>
#include "../models/Song.h"

using namespace std;

class IAudioPlayer
{
public:
    virtual void play(const Song &song) = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual ~IAudioPlayer() = default;
};