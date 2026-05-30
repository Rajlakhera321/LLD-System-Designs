#include "./StorageFactoryCreation.h"

IStorage *StorageFactoryCreation::createStorage(const std::string &type)
{
    if (type == "DB")
    {
        return new DBStorage();
    }
    else if (type == "Redis")
    {
        return new RedisStorage();
    }
    return nullptr; // Return nullptr for unsupported storage types
}