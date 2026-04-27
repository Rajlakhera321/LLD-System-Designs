#pragma once
#include <bits/stdc++.h>

using namespace std;

class IObserver
{
public:
    virtual void notify(const string message) = 0;
    virtual ~IObserver() {}
};