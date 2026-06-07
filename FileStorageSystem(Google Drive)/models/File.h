#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IDriveItems.h"

class File : public IDriveItems
{
private:
    std::string name;
    int size;

public:
    File(const std::string &name, int size);

    std::string getName() const override;

    void display(int depth) const override;
};