#include "./FileMetaData.h"

FileMetaData::FileMetaData(const std::string &name, int size, const std::string &type)
    : name(name), size(size), type(type), file(file) {}

std::string FileMetaData::getName() const
{
    return name;
}

int FileMetaData::getSize() const
{
    return size;
}

std::string FileMetaData::getType() const
{
    return type;
}