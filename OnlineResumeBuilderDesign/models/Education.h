#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"

using namespace std;

class Education : public Section
{
private:
    vector<unique_ptr<string> > educationList;

public:
    void addEducation(unique_ptr<string> education)
    {
        educationList.push_back(move(education));
    }

    void render() override
    {
        cout << "Education:" << endl;
        for (const auto &edu : educationList)
        {
            cout << "- " << *edu << endl;
        }
    }
};