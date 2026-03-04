#pragma once
#include <bits/stdc++.h>

class IObserver
{
public:
    virtual void update(double amount) = 0;
    virtual ~IObserver() = default;
};