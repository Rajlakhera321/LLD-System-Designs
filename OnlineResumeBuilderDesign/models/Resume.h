#pragma once
#include <bits/stdc++.h>

using namespace std;

class Resume
{
private:
    vector<unique_ptr<Section> > sections;

public:
    void addSection(unique_ptr<Section> section)
    {
        sections.push_back(move(section));
    }

    void render()
    {
        cout << "Resume:" << endl;
        for (const auto &section : sections)
        {
            section->render();
            cout << endl; // Add a newline between sections
        }
    }
}