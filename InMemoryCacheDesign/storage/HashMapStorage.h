#pragma once
#include <bits/stdc++.h>
#include "../models/Node.h"
#include "./IStorage.h"

using namespace std;

class HashMapStorage : public IStorage
{
private:
    unordered_map<int, Node *> mp;

public:
    Node *get(int key) override;
    void put(int key, Node *node) override;
    void remove(int key) override;
    bool exists(int key) override;
    int size() override;
};