#pragma once
#include <bits/stdc++.h>

class IUserInterface
{
    virtual std::string getName() const = 0;
    virtual int getId() const = 0;

    virtual ~IUserInterface() = default;
};