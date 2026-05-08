#include "./MusicController.h"

void MusicController::play()
{
    Song *currentSong = playList.getCurrentSong();
    if (!currentSong) {
        observer.notify("No songs in the playlist.");
        return;
    }
    observer.notify(
        "Now playing: " +
        currentSong->getName() +
        " by " +
        currentSong->getArtist());
}

void MusicController::pause()
{
    if (playerState == PlayState::Playing)
    {
        audioPlayer.pause();

        playerState = PlayState::Paused;

        observer.notify("Song paused.");
    }
}

void MusicController::stop()
{
    if (playerState != PlayState::Stopped)
    {
        audioPlayer.stop();

        playerState = PlayState::Stopped;

        observer.notify("Song stopped.");
    }
}

void MusicController::next()
{
    Song *nextSong = playStrategy->next(&playList);

    if (nextSong)
    {
        audioPlayer.play(*nextSong);

        playerState = PlayState::Playing;

        observer.notify(
            "Now playing: " +
            nextSong->getName() +
            " by " +
            nextSong->getArtist());
    }
}

void MusicController::prev()
{
    Song *prevSong = playStrategy->prev(&playList);

    if (prevSong)
    {
        audioPlayer.play(*prevSong);

        playerState = PlayState::Playing;

        observer.notify(
            "Now playing: " +
            prevSong->getName() +
            " by " +
            prevSong->getArtist());
    }
}