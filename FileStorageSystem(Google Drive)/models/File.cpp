#include "./File.h"

File::File(const std::string &name, int size, FileMetaData *filemetadata) : name(name), size(size), filemetadata(filemetadata) {}

std::string File::getName() const
{
    return name;
}

FileMetaData *File::getFileMetaData() const
{
    return filemetadata;
}

void File::display(int depth) const
{
    for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "- " << name << " (" << size << " KB)" << std::endl;
}