#pragma once
#include <bits/stdc++.h>
#include "./Node.h"

using namespace std;

class Storage
{
private:
    unordered_map<int, Node *> mp;

public:
    Node *get(int key);
    void put(int key, int value);
    void remove(int key);
    bool exists(int key);
    int size();
};