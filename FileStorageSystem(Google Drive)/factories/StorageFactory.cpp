#include "./StorageFactory.h"

IStorage *StorageFactory::createStorage(const std::string &type)
{
    if (type == "local")
    {
        return new LocalStorage();
    }
    else if (type == "s3")
    {
        return new S3Storage();
    }
    else
    {
        throw std::invalid_argument("Invalid storage type");
    }
}