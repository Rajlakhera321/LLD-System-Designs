#include "./LocalStorage.h"

void LocalStorage::saveFile(const std::string &path, const std::string &content)
{
    storage[path] = content;
}

std::string LocalStorage::readFile(const std::string &path)
{
    if (storage.find(path) != storage.end())
    {
        return storage[path];
    }
    return "";
}

void LocalStorage::deleteFile(const std::string &path)
{
    storage.erase(path);
}