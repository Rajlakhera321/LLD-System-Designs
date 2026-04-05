#pragma once
#include <bits/stdc++.h>
#include "./Player.h"

using namespace std;

class Move
{
private:
    Player *player;
    int diceRoll;
    int from;
    int to;

public:
    Move(Player *p, int roll, int f, int t) : player(p), diceRoll(roll), from(f), to(t) {}

    Player *getPlayer() const { return player; }

    int getDiceRoll() const { return diceRoll; }

    int getFrom() const { return from; }

    int getTo() const { return to; }
};