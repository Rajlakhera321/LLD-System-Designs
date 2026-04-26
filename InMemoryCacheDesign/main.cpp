#include <bits/stdc++.h>
#include "./cache/Cache.h"
#include "./eviction/LRU.h"
#include "./storage/IStorage.h"
#include "./models/Node.h"
#include "./eviction/EvictionPolicy.h"
#include "./factory/EvictionFactory.h"
#include "./storage/HashMapStorage.h"

int main()
{
    IStorage *storage = new HashMapStorage();
    EvictionPolicy *eviction = EvictionFactory::createEvictionPolicy("LRU");
    Cache cache(2, eviction, storage);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);              // evicts key 2
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);              // evicts key 3
    cout << cache.get(3) << endl; // returns 3 (not found)
    cout << cache.get(4) << endl; // returns 4

    return 0;
}