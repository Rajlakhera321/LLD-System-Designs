#include "./Storage.h"

Node *Storage::get(int key)
{
    if (mp.count(key))
        return mp[key];

    return NULL;
}

void Storage::put(int key, Node *node)
{
    mp[key] = node;
}

void Storage::remove(int key)
{
    mp.erase(key);
}

bool Storage::exists(int key)
{
    return mp.count(key);
}

int Storage::size()
{
    return mp.size();
}