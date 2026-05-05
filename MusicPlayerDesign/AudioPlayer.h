#pragma once
#include <bits/stdc++.h>
#include "./interfaces/IAudioPlayer.h"
#include "./enums/PlayState.h"
#include "./interfaces/IPlayStrategy.h"

using namespace std;

class AudioPlayer : public IAudioPlayer
{
private:
    PlayState state;

public:
    void play(const Song &song) override;
    void pause() override;
    void stop() override;
};