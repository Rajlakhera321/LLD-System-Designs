#pragma once
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node *head;
    int key;
    int value;

    Node *prev;
    Node *next;

    int freq;
};