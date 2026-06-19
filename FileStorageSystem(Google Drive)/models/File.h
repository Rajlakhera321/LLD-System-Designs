#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IDriveItems.h"
#include "./FileMetaData.h"

class File : public IDriveItems
{
private:
    std::string name;
    int size;
    FileMetaData *filemetadata;

public:
    File(const std::string &name, int size, FileMetaData *filemetadata);

    std::string getName() const override;

    void display(int depth) const override;

    FileMetaData *getFileMetaData() const;
};