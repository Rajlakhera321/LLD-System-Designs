#pragma once

#include "bits/stdc++.h"
#include "./File.h"

class FileMetaData
{
private:
    std::string name;
    int size;
    std::string type;

public:
    FileMetaData(const std::string &name, int size, const std::string &type);

    std::string getName() const;

    int getSize() const;

    std::string getType() const;
};