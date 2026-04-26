#include "./LRU.h"

void LRU::keyAccessed(Node *node)
{
    if (node == head)
        return;

    if (node->prev != NULL)
        node->prev->next = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    if (node == tail)
        tail = tail->prev;

    node->prev = NULL;
    node->next = head;

    if (head != NULL)
        head->prev = node;

    head = node;

    if (tail == NULL)
        tail = head;
}

void LRU::addNode(Node *node)
{
    node->prev = NULL;
    node->next = head;

    if (head != NULL)
        head->prev = node;

    head = node;

    if (tail == NULL)
        tail = head;
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