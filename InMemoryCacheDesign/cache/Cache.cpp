#include "./Cache.h"

int Cache::get(int key)
{
    if (!storage->exists(key))
        return -1;

    Node *node = storage->get(key);
    eviction->keyAccessed(node);
    return node->value;
}

void Cache::put(int key, int value)
{
    if (storage->exists(key))
    {
        Node *node = storage->get(key);
        node->value = value;
        eviction->keyAccessed(node);
        return;
    }

    if (storage->size() == capacity)
    {
        Node *node = eviction->evict();
        storage->remove(node->key);
    }

    Node *node = new Node(key, value);
    eviction->addNode(node);
    storage->put(key, node);
}

void Cache::remove(int key)
{
    if (!storage->exists(key))
        return;

    Node *node = storage->get(key);
    eviction->keyAccessed(node);
    storage->remove(key);
}