#pragma once
#include <bits/stdc++.h>
#include <unordered_map>
#include <list>

#include "./EvictionPolicy.h"
#include "../models/Node.h"

using namespace std;

class LFU : public EvictionPolicy
{
private:
    unordered_map<int, list<Node *> > freqMap;
    unordered_map<Node *, int> nodeFreq;
    int minFreq = 0;

public:
    void keyAccessed(Node *node) override;
    void addNode(Node *node) override;
    Node *evict() override;
};