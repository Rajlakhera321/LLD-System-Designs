#include "./Song.h"

string Song::getName() const
{
    return name;
}

string Song::getArtist() const
{
    return artist;
}

int Song::getDuration() const
{
    return duration;
}