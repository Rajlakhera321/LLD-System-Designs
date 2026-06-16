#pragma once

#include "bits/stdc++.h"
#include "./File.h"

class FileMetaData
{
private:
    std::string name;
    int size;
    std::string type;
    File *file;

public:
    FileMetaData(const std::string &name, int size, const std::string &type, File *file);

    std::string getName() const;

    int getSize() const;

    std::string getType() const;

    File *getFile() const;
};