#include <bits/stdc++.h>
#include "./Cache.h"
#include "./LRU.h"
#include "./Storage.h"
#include "./Node.h"
#include "./Eviction.h"

int main()
{
    Storage *storage = new Storage();
    Eviction *eviction = new LRU();
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