#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IGameObserver.h"

using namespace std;

class ConsoleLogger : public IGameObserver
{
public:
    void onMove(const Move &move) override
    {
        // Log the move details to the console
        cout << "Player " << move.getPlayer()->getName() << " rolled a " << move.getDiceRoll()
             << " and moved from " << move.getFrom() << " to " << move.getTo() << endl;
    }
};