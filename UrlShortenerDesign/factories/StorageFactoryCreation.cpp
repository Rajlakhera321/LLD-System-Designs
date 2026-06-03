#include "./StorageFactoryCreation.h"

std::unique_ptr<IStorage> StorageFactoryCreation::createStorage(const std::string &type)
{
    if (type == "DB")
    {
        return std::make_unique<DBStorage>();
    }
    return nullptr;
}