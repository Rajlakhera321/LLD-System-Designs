#pragma once
#include <bits/stdc++.h>

using namespace std;

class Section
{
public:
    virtual void render() = 0; // Pure virtual function to display section content
    virtual ~Section() {}      // Virtual destructor for proper cleanup
};