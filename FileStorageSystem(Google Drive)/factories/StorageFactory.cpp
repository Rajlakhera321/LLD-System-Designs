#include "./StorageFactory.h"

std::unique_ptr<IStorage> StorageFactory::createStorage(const std::string &type)
{
    if (type == "local")
    {
        return std::unique_ptr<IStorage>(new LocalStorage());
    }
    else if (type == "s3")
    {
        return std::unique_ptr<IStorage>(new S3Storage());
    }
    else
    {
        throw std::invalid_argument("Invalid storage type");
    }
}