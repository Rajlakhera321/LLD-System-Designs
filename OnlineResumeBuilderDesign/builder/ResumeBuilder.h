#pragma once
#include <bits/stdc++.h>
#include "../models/Resume.h"
#include "../models/BasicDetails.h"
#include "../models/Summary.h"
#include "../models/Skills.h"
#include "../models/Experiences.h"
#include "../models/Education.h"
#include "../models/Projects.h"

using namespace std;

class ResumeBuilder
{
private:
    unique_ptr<Resume> resume;

    BasicDetails *basicDetails = nullptr;
    Skills *skills = nullptr;
    Experiences *experiences = nullptr;
    Education *education = nullptr;
    Projects *projects = nullptr;

public:
    ResumeBuilder()
    {
        resume = make_unique<Resume>();
    }

    ResumeBuilder &addBasicDetails(string name, string email, string phone)
    {
        auto section = make_unique<BasicDetails>(name, email, phone);
        basicDetails = section.get();
        resume->addSection(move(section));
        return *this;
    }

    ResumeBuilder &addSummary(string text)
    {
        resume->addSection(make_unique<Summary>(text));
        return *this;
    }

    ResumeBuilder &addSkill(string skill)
    {
        if (!skills)
        {
            auto section = make_unique<Skills>();
            skills = section.get();
            resume->addSection(move(section));
        }
        skills->addSkill(make_unique<string>(skill));
        return *this;
    }

    ResumeBuilder &addExperience(string exp)
    {
        if (!experiences)
        {
            auto section = make_unique<Experiences>();
            experiences = section.get();
            resume->addSection(move(section));
        }
        experiences->addExperience(make_unique<string>(exp));
        return *this;
    }

    ResumeBuilder &addEducation(string edu)
    {
        if (!education)
        {
            auto section = make_unique<Education>();
            education = section.get();
            resume->addSection(move(section));
        }
        education->addEducation(make_unique<string>(edu));
        return *this;
    }

    ResumeBuilder &addProject(string proj)
    {
        if (!projects)
        {
            auto section = make_unique<Projects>();
            projects = section.get();
            resume->addSection(move(section));
        }
        projects->addProject(make_unique<string>(proj));
        return *this;
    }

    unique_ptr<Resume> build()
    {
        return move(resume);
    }
};