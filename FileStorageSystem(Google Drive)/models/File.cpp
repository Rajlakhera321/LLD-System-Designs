#include "./File.h"

File::File(const std::string &name, int size) : name(name), size(size) {}

std::string File::getName() const
{
    return name;
}

void File::display(int depth) const
{
    for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "- " << name << " (" << size << " KB)" << std::endl;
}