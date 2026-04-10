#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/ExperienceDto.h"

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

    SectionType getType() override
    {
        return SectionType::EXPERIENCE;
    }

    void update(void *data) override
    {
        ExperienceDto *dto = static_cast<ExperienceDto *>(data);

        experienceList.push_back(make_unique<string>(dto->exp));
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