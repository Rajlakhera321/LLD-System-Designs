#pragma once
#include <bits/stdc++.h>

using namespace std;

class Storage
{
private:
    unordered_map<int, int> mp;

public:
    int get(int key);
    void put(int key, int value);
    void remove(int key);
};