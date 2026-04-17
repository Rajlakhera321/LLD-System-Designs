#pragma once
#include <bits/stdc++.h>
#include "./LRU.h"
#include "./Storage.h"
#include "./Node.h"
#include "./Eviction.h"

using namespace std;

class Cache
{
private:
    Storage storage;
    LRU eviction;

public:
    int get(int key);

    void put(int key, int value);

    void remove(int key);
}