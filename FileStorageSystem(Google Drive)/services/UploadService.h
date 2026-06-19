#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"

class UploadService
{
private:
    std::unique_ptr<IStorage> storage;

public:
    UploadService(std::unique_ptr<IStorage> stor);
    void upload(const std::string &path, const std::string &content);
};