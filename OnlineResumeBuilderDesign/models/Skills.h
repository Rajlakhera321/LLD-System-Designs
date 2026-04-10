#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/SkillDto.h"

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

    SectionType getType() override
    {
        return SectionType::SKILLS;
    }

    void update(void *data) override
    {
        SkillDto *dto = static_cast<SkillDto *>(data);

        skillList.push_back(make_unique<string>(dto->skill));
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