#pragma once
#include <bits/stdc++.h>

using namespace std;

class ResumeService
{
private:
    Resume *resume;
    Section *section;

public:
    ResumeService(Resume *resume) : resume(resume) {}
    void setSection(Section *section)
    {
        this->section = section;
    }

    void update(void *data)
    {
        section->update(data);
    }
};