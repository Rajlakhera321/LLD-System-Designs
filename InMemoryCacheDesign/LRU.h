#pragma once
#include <bits/stdc++.h>
#include "./Eviction.h"

using namespace std;

class LRU : public Evicton
{
public:
    void keyAccessed(Node *node);
    Node *evict();
};