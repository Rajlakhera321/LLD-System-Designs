#pragma once
#include <bits/stdc++.h>
#include "../repositories/RiderRepository.h"

using namespace std;

class RiderService
{
private:
    RiderRepository *riderRepo;

public:
    RiderService(RiderRepository *riderRepo) : riderRepo(riderRepo) {}

    void addRider(string name, string phoneNo)
    {
        Rider *rider = new Rider(name, phoneNo);
        riderRepo->addRider(rider);
        cout << "Rider added: " << rider->getName() << " with ID: " << rider->getId() << endl;
    }

    Rider *getRiderById(int id)
    {
        return riderRepo->getRiderById(id);
    }
};