#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"

class UploadService
{
private:
    IStorage *storage;

public:
    UploadService(IStorage *stor);
    void upload(const std::string &path, const std::string &content);
};