#pragma once
#include <bits/stdc++.h>
#include "../models/Node.h"

using namespace std;

class EvictionPolicy
{
public:
    virtual void addNode(Node *node) = 0;
    virtual void keyAccessed(Node *node) = 0;
    virtual Node *evict() = 0;
    virtual ~EvictionPolicy() = default;
};