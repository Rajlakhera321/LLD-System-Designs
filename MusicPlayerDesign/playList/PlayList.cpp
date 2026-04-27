#include "./PlayList.h"

void PlayList::addSong(const Song &song)
{
    songs.push_back(song);
}

void PlayList::removeSong(const string &songName)
{
    for (vector<Song>::iterator it = songs.begin(); it != songs.end(); ++it)
    {
        if (it->getName() == songName)
        {
            songs.erase(it);
            if (currentIndex >= songs.size())
                currentIndex = 0;
            return;
        }
    }
}

Song *PlayList::getCurrentSong()
{
    if (songs.empty())
        return nullptr;

    return &songs[currentIndex];
}

Song *PlayList::playNext()
{
    if (songs.empty())
        return nullptr;

    currentIndex = (currentIndex + 1) % songs.size();
    return &songs[currentIndex];
}

Song *PlayList::playPrevious()
{
    if (songs.empty())
        return nullptr;

    currentIndex = (currentIndex - 1 + songs.size()) % songs.size();
    return &songs[currentIndex];
}