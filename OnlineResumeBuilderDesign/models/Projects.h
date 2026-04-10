#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/ProjectDto.h"

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

    SectionType getType() override
    {
        return SectionType::PROJECT;
    }

    void update(void *data) override
    {
        ProjectDto *dto = static_cast<ProjectDto *>(data);

        projectList.push_back(make_unique<string>(dto->project));
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