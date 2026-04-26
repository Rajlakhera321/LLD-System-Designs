#pragma once
#include <bits/stdc++.h>
#include "../models/Node.h"

using namespace std;

class IStorage
{
public:
    virtual Node *get(int key) = 0;
    virtual void put(int key, Node *node) = 0;
    virtual void remove(int key) = 0;
    virtual bool exists(int key) = 0;
    virtual int size() = 0;
    virtual ~IStorage() = default;
};