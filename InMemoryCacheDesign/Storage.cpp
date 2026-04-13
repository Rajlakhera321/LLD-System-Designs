#pragma once
#include <bits/stdc++.h>
#include "./Storage.h"
#include "./Node.h"

using namespace std;

int Storage::get(int key)
{
    if (mp.find(key) == mp.end())
    {
        return -1;
    }

    Node *node = mp[key];

    Node *prev = node->prev;
    Node *next = node->next;

    if (prev != NULL)
    {
        prev->next = next;
    }

    if (next != NULL)
    {
        next->prev = prev;
    }

    Node *headNode = head;
    head = node;
    head->prev = NULL;
    headNode->prev = head;
    head->next = headNode;

    return node->value;
}

void Storage::put(int key, int value)
{
    mp[key] = value;
}

void Storage::remove(int key)
{
    mp.erase(key);

    Node *node = mp[key];

    Node *prev = node->prev;
    Node *next = node->next;

    if (prev != NULL)
    {
        prev->next = next;
    }

    if (next != NULL)
    {
        next->prev = prev;
    }
}