#pragma once
#include <bits/stdc++.h>
#include "./models/Song.h"
#include "./interfaces/IAudioPlayer.h"
#include "./enums/PlayState.h"
#include "./interfaces/IObserver.h"
#include "./playList/PlayList.h"
#include "./interfaces/IPlayStrategy.h"

using namespace std;

class MusicController
{
private:
    PlayList &playList;
    IAudioPlayer &audioPlayer;
    PlayState playerState;
    IObserver &observer;
    std::unique_ptr<IPlayStrategy> playStrategy;

public:
    MusicController(
        PlayList &pl,
        IAudioPlayer &ap,
        IObserver &obs,
        std::unique_ptr<IPlayStrategy> ps)
        : playList(pl),
          audioPlayer(ap),
          playerState(PlayState::Stopped),
          observer(obs),
          playStrategy(std::move(ps)) {}

    void play();

    void pause();

    void stop();

    void next();

    void prev();
};