#include "./MusicController.h"

void MusicController::play()
{
    Song *currentSong = playList->getCurrentSong();

    if (currentSong)
    {
        audioPlayer->play(*currentSong);
        playerState = PlayState::Playing;
        if (observer)
        {
            observer->notify("Now playing: " + currentSong->getName() + " by " + currentSong->getArtist());
        }
    }
}

void MusicController::pause()
{
    if (playerState == PlayState::Playing)
    {
        audioPlayer->pause();
        playerState = PlayState::Paused;
        if (observer)
        {
            observer->notify("Song paused.");
        }
    }
}

void MusicController::stop()
{
    if (playerState != PlayState::Stopped)
    {
        audioPlayer->stop();
        playerState = PlayState::Stopped;
        if (observer)
        {
            observer->notify("Song stopped.");
        }
    }
}

void MusicController::next()
{
    Song *nextSong = playList->playNext();

    if (nextSong)
    {
        audioPlayer->play(*nextSong);
        playerState = PlayState::Playing;
        if (observer)
        {
            observer->notify("Now playing: " + nextSong->getName() + " by " + nextSong->getArtist());
        }
    }
}

void MusicController::prev()
{
    Song *prevSong = playList->playPrevious();

    if (prevSong)
    {
        audioPlayer->play(*prevSong);
        playerState = PlayState::Playing;
        if (observer)
        {
            observer->notify("Now playing: " + prevSong->getName() + " by " + prevSong->getArtist());
        }
    }
}