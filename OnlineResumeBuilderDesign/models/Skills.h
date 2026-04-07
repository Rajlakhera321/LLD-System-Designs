#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"

using namespace std;

class Skills : public Section
{
private:
    vector<unique_ptr<string> > skillList;

public:
    void addSkill(unique_ptr<string> skill)
    {
        skillList.push_back(move(skill));
    }

    void render() override
    {
        cout << "Skills:" << endl;
        for (const auto &skill : skillList)
        {
            cout << "- " << *skill << endl;
        }
    }
};