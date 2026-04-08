#pragma once
#include <bits/stdc++.h>

using namespace std;

class ITemplateInterface
{
public:
    virtual void render(Resume &resume) = 0;
    virtual ~ITemplateInterface() {};
};