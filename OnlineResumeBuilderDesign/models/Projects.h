#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"

using namespace std;

class Projects : public Section
{
private:
    vector<unique_ptr<string> > projectList;

public:
    void addProject(unique_ptr<string> project)
    {
        projectList.push_back(move(project));
    }

    void render() override
    {
        cout << "Projects:" << endl;
        for (const auto &proj : projectList)
        {
            cout << "- " << *proj << endl;
        }
    }
};