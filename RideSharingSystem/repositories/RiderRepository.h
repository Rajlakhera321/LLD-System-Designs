#pragma once
#include <bits/stdc++.h>
#include "../models/Rider.h"

using namespace std;

class RiderRepository
{
private:
    vector<Rider *> riders;

public:
    void addRider(Rider *rider)
    {
        cout << "Adding rider: " << rider->getName() << " with ID: " << rider->getId() << endl;
        riders.push_back(rider);
    }

    Rider *getRiderById(int id)
    {
        for (auto rider : riders)
        {
            if (rider->getId() == id)
            {
                return rider;
            }
        }
        return nullptr;
    }
};