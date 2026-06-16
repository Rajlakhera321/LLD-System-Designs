#include "./S3Storage.h"

void S3Storage::saveFile(const std::string &path, const std::string &content)
{
    storage[path] = content;
}

std::string S3Storage::readFile(const std::string &path)
{
    if (storage.find(path) != storage.end())
    {
        return storage[path];
    }
    return "";
}

void S3Storage::deleteFile(const std::string &path)
{
    storage.erase(path);
}