#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"

class LocalStorage : public IStorage
{
private:
    std::map<std::string, std::string> storage;

public:
    void saveFile(const std::string &path, const std::string &content) override;
    std::string readFile(const std::string &path) override;
    void deleteFile(const std::string &path) override;
};