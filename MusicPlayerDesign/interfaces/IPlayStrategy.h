#pragma once
#include <bits/stdc++.h>
#include "../playList/PlayList.h"
#include "../models/Song.h"

using namespace std;

class IPlayStrategy
{
public:
    virtual Song *next(PlayList *playlist) = 0;
    virtual Song *prev(PlayList *playlist) = 0;
    virtual ~IPlayStrategy() {}
};