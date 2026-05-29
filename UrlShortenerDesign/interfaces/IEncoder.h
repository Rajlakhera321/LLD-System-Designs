#pragma once
#include "bits/stdc++.h"

class IEncoder
{
public:
    virtual std::string encode(long long id) = 0;

    virtual ~IEncoder() {}
};