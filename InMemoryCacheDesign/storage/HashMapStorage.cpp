#include "./HashMapStorage.h"

Node *HashMapStorage::get(int key)
{
    if (mp.count(key))
        return mp[key];

    return NULL;
}

void HashMapStorage::put(int key, Node *node)
{
    mp[key] = node;
}

void HashMapStorage::remove(int key)
{
    mp.erase(key);
}

bool HashMapStorage::exists(int key)
{
    return mp.count(key);
}

int HashMapStorage::size()
{
    return mp.size();
}