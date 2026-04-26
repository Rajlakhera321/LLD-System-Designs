#pragma once
#include <bits/stdc++.h>
#include "./EvictionPolicy.h"
#include "../models/Node.h"

using namespace std;

class LRU : public EvictionPolicy
{
private:
    Node *head;
    Node *tail;

public:
    LRU() : head(NULL), tail(NULL) {};
    void addNode(Node *node) override;
    void keyAccessed(Node *node) override;
    Node *evict() override;
};