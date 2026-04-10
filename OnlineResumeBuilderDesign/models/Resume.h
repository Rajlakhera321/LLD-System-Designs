#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../enums/SectionType.h"

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

    Section *getSectionByType(SectionType type)
    {
        for (auto &sec : sections)
        {
            if (sec->getType() == type)
                return sec.get();
        }

        return nullptr;
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
};