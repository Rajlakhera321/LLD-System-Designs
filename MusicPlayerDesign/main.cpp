#include <bits/stdc++.h>
#include "./models/Song.h"
#include "./playList/PlayList.h"
#include "./AudioPlayer.h"
#include "./MusicController.h"
#include "./observers/NotifyUser.h"
#include "./enums/PlayState.h"
#include "./interfaces/IAudioPlayer.h"
#include "./interfaces/IObserver.h"

int main()
{
    PlayList playList;
    
    playList.addSong(Song("Shape of You", "Ed Sheeran", 240));
    playList.addSong(Song("Blinding Lights", "The Weeknd", 200));
    playList.addSong(Song("Levitating", "Dua Lipa", 220));

    AudioPlayer audioPlayer;
    NotifyUser notifyUser;

    MusicController musicController(&playList, &audioPlayer, &notifyUser);

    musicController.play();
    musicController.next();
    musicController.pause();
    musicController.prev();
    musicController.stop();

    return 0;
}