#pragma once

#include "bits/stdc++.h"

class IStorage
{
public:
    virtual void saveFile(const std::string &path, const std::string &content) = 0;

    virtual std::string readFile(const std::string &path) = 0;

    virtual void deleteFile(const std::string &path) = 0;

    virtual ~IStorage() {}
};