#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"

using namespace std;

class Experiences : public Section
{
private:
    vector<unique_ptr<string> > experienceList;

public:
    void addExperience(unique_ptr<string> experience)
    {
        experienceList.push_back(move(experience));
    }

    void render() override
    {
        cout << "Experiences:" << endl;
        for (const auto &exp : experienceList)
        {
            cout << "- " << *exp << endl;
        }
    }
};