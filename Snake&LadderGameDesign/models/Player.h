#pragma once
#include <bits/stdc++.h>

using namespace std;

class Player
{
private:
    int id;
    string name;
    int position;

public:
    Player(int playerId, string playerName) : id(playerId), name(playerName), position(0) {}

    int getId() const { return id; }
    string getName() const { return name; }
    int getPosition() const { return position; }

    void setPosition(int newPosition) { position = newPosition; }
};