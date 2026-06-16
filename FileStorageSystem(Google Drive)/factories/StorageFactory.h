#pragma once

#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"
#include "../storage/LocalStorage.h"
#include "../storage/S3Storage.h"

class StorageFactory
{
public:
    static IStorage *createStorage(const std::string &type);
};