#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IDriveItems.h"

class Folder : public IDriveItems
{
private:
    std::string name;
    std::vector<IDriveItems *> items;

public:
    Folder(const std::string &name);

    void addItem(IDriveItems *item);

    std::string getName() const override;

    void display(int depth) const override;
};