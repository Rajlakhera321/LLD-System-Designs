#pragma once
#include <bits/stdc++.h>

using namespace std;

class IDiceStrategy
{
public:
    virtual int roll() = 0;
    virtual ~IDiceStrategy() {}
};