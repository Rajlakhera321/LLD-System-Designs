#pragma once
#include <bits/stdc++.h>
#include "./Node.h"

using namespace std;

class Evicton
{
public:
    virtual void addNode(Node *node) = 0;
    virtual void keyAccessed(Node *node) = 0;
    virtual Node *evict() = 0;
    virtual ~Evicton() = default;
};