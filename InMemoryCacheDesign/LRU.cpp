#pragma once
#include <bits/stdc++.h>
#include "./LRU.h"

void LRU::keyAccessed(Node *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
    node->prev = NULL;
    node->next = head;
    head->prev = node;
    head = node;
}

Node *LRU::evict()
{
    Node *node = tail;
    if (tail->prev != NULL)
    {
        tail->prev->next = NULL;
    }
    tail = tail->prev;
    return node;
}