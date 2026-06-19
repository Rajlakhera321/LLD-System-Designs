#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IDriveItems.h"

class Folder : public IDriveItems
{
private:
    std::string name;
    std::vector<std::shared_ptr<IDriveItems> > items;

public:
    Folder(const std::string &name);

    void addItem(std::shared_ptr<IDriveItems> item);

    std::string getName() const override;

    void display(int depth) const override;
};