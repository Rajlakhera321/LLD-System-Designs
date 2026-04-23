#pragma once
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int key;
    int value;

    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
};