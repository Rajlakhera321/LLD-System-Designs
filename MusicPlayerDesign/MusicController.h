#pragma once
#include <bits/stdc++.h>
#include "./models/Song.h"
#include "./interfaces/IAudioPlayer.h"
#include "./enums/PlayState.h"
#include "./interfaces/IObserver.h"
#include "./playList/PlayList.h"

using namespace std;

class MusicController
{
private:
    PlayList *playList;
    IAudioPlayer *audioPlayer;
    PlayState playerState;
    IObserver *observer;

public:
    MusicController(PlayList *pl, IAudioPlayer *ap, IObserver *obs) : playList(pl), audioPlayer(ap), playerState(PlayState::Stopped), observer(obs) {}

    void play();

    void pause();

    void stop();

    void next();

    void prev();
};