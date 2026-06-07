#pragma once
#include "bits/stdc++.h"

class IDriveItems
{
public:
    virtual std::string getName() const = 0;

    virtual void display(int depth) const = 0;

    virtual ~IDriveItems() {}
};