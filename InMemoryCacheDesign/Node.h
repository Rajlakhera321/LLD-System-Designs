#pragma once
#include <bits/stdc++.h>

using namespace std;

class Node
{
private:
    int key;
    int value;

    Node *prev;
    Node *next;

    int freq;
}