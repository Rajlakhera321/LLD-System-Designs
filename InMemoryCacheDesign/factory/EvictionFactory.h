#pragma once
#include <bits/stdc++.h>
#include "../eviction/EvictionPolicy.h"
#include "../eviction/LRU.h"
#include "../eviction/LFU.h"

using namespace std;

class EvictionFactory
{
public:
    static EvictionPolicy *createEvictionPolicy(const string &policyType);
};