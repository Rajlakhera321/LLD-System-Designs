#pragma once
#include <bits/stdc++.h>

using namespace std;

class ConsoleLogger : public IGameObserver
{
public:
    void onMove(unique_ptr<Move> move) override
    {
        // Log the move details to the console
        cout << "Player " << move->getPlayer()->getName() << " rolled a " << move->getDiceRoll()
             << " and moved from " << move->getFrom() << " to " << move->getTo() << endl;
    }
};