#pragma once
#include "bits/stdc++.h"
#include "../interfaces/ICache.h"
#include "../storages/RedisStorage.h"

class CacheFactoryCreation
{
public:
    static std::unique_ptr<ICache> createCache(const std::string &type);
};