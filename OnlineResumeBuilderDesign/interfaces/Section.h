#pragma once
#include <bits/stdc++.h>
#include "../enums/SectionType.h"

using namespace std;

class Section
{
public:
    virtual void render() = 0; // Pure virtual function to display section content
    virtual SectionType getType() = 0;
    virtual void update(void *data) = 0;
    virtual ~Section() {} // Virtual destructor for proper cleanup
};