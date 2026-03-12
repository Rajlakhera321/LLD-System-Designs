#pragma once
#include <bits/stdc++.h>
#include "../repositories/BeverageRepository.h"

using namespace std;

class BeverageService
{
private:
    BeverageRepository *beverageRepo;

public:
    BeverageService(BeverageRepository *beverageRepo) : beverageRepo(beverageRepo) {}

    Beverage *getBeverage(BeverageEnum name)
    {
        return beverageRepo->getBeverage(name);
    }

    bool hasBeverage(BeverageEnum name)
    {
        return beverageRepo->hasBeverage(name);
    }

    void addBeverage(BeverageEnum name, Beverage bev)
    {
        beverageRepo->addBeverage(name, bev);
    }
};