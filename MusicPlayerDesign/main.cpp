#include <bits/stdc++.h>

#include "./models/Song.h"
#include "./playList/PlayList.h"
#include "./AudioPlayer.h"
#include "./MusicController.h"
#include "./observers/NotifyUser.h"
#include "./enums/PlayState.h"
#include "./interfaces/IAudioPlayer.h"
#include "./interfaces/IObserver.h"
#include "./interfaces/IPlayStrategy.h"
#include "./factories/PlaySongFactory.h"

int main()
{
    PlayList playList;
    playList.addSong(Song("Shape of You", "Ed Sheeran", 240));
    playList.addSong(Song("Blinding Lights", "The Weeknd", 200));
    playList.addSong(Song("Levitating", "Dua Lipa", 220));

    std::unique_ptr<IPlayStrategy> playStrategy = PlaySongFactory::createPlayStrategy("sequential");
    AudioPlayer audioPlayer;
    NotifyUser notifyUser;

    MusicController musicController(playList, audioPlayer, notifyUser, std::move(playStrategy));

    musicController.play();
    musicController.next();
    musicController.pause();
    musicController.prev();
    musicController.stop();

    return 0;
}