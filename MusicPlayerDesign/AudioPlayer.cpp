#include "./AudioPlayer.h"

void AudioPlayer::play(const Song &song)
{
    state = PlayState::Playing;
    cout << "Playing: " << song.getName() << " by " << song.getArtist() << endl;
}

void AudioPlayer::pause()
{
    state = PlayState::Paused;
}

void AudioPlayer::stop()
{
    state = PlayState::Stopped;
}