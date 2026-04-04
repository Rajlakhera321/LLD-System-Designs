#pragma once
#include <bits/stdc++.h>

using namespace std;

class Move
{
private:
    unique_ptr<Player> player;
    int diceRoll;
    int from;
    int to;

public:
    Move(unique_ptr<Player> p, int roll, int f, int t) : player(move(p)), diceRoll(roll), from(f), to(t) {}

    unique_ptr<Player> getPlayer() const { return move(player); }

    int getDiceRoll() const { return diceRoll; }

    int getFrom() const { return from; }

    int getTo() const { return to; }
};