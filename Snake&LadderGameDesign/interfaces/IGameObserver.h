#pragma once
#include <bits/stdc++.h>
#include "../models/Move.h"

using namespace std;

class IGameObserver
{
public:
    virtual void onMove(unique_ptr<Move> move) = 0;
    virtual ~IGameObserver() {}
};