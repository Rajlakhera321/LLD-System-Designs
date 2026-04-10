#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/EducationDto.h"

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

    SectionType getType() override
    {
        return SectionType::EDUCATION;
    }

    void update(void *data) override
    {
        EducationDto *dto = static_cast<EducationDto *>(data);

        educationList.push_back(make_unique<string>(dto->edu));
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