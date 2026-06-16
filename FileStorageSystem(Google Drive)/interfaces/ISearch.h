#pragma once

#include "bits/stdc++.h"

class ISearch
{
public:
    virtual std::vector<std::string> search(const std::string &query) = 0;

    virtual ~ISearch() {}
};