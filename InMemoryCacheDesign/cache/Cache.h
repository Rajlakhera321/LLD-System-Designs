#pragma once
#include <bits/stdc++.h>
#include "../eviction/LRU.h"
#include "../storage/IStorage.h"
#include "../models/Node.h"
#include "../eviction/EvictionPolicy.h"

using namespace std;

class Cache
{
private:
    IStorage *storage;
    EvictionPolicy *eviction;
    int capacity;

public:
    Cache(int capacity, EvictionPolicy *eviction, IStorage *storage) : capacity(capacity), eviction(eviction), storage(storage) {};
    int get(int key);
    void put(int key, int value);
    void remove(int key);
};