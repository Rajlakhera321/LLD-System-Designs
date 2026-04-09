#pragma once
#include <bits/stdc++.h>

using namespace std;

class Resume;
class ITemplateInterface
{
public:
    virtual void render(Resume &resume) = 0;
    virtual ~ITemplateInterface() {};
};