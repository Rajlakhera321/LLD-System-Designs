#include "./CacheFactoryCreation.h"

std::unique_ptr<ICache> CacheFactoryCreation::createCache(const std::string &type)
{
    if (type == "Redis")
    {
        return std::make_unique<RedisStorage>();
    }
    return nullptr;
}