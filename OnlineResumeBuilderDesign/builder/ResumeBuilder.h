#pragma once
#include <bits/stdc++.h>
#include "../models/Resume.h"
#include "../models/"

using namespace std;

class ResumeBuilder
{
private:
    Resume &resume;

public:
    ResumeBuilder(Resume &resume) : resume(resume) {};

    void addSection(Section &section)
    {
    }
}