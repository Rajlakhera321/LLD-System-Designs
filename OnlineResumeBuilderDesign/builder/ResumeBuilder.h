#pragma once
#include <bits/stdc++.h>
#include "../models/Resume.h"
#include "../models/"

using namespace std;

class ResumeBuilder
{
private:
    unique_ptr<Resume> resume;
    BasicDetials *basicDetails;

public:
    ResumeBuilder(unique_ptr<Resume> resume) : resume(move(resume)) {};
}