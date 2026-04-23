#pragma once
#include <bits/stdc++.h>
#include "./Eviction.h"
#include "./Node.h"

using namespace std;

class LRU : public Eviction
{
private:
    Node *head;
    Node *tail;

public:
    LRU();
    void addNode(Node *node) override;
    void keyAccessed(Node *node) override;
    Node *evict() override;
};