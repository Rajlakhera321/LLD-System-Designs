#include "./Folder.h"

Folder::Folder(const std::string &name) : name(name) {}

void Folder::addItem(IDriveItems *item)
{
    items.push_back(item);
}

std::string Folder::getName() const
{
    return name;
}

void Folder::display(int depth) const
{
    for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "+ " << name << std::endl;

    for (const auto &item : items)
    {
        item->display(depth + 1);
    }
}