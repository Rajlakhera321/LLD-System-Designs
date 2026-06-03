#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"
#include "../storages/DBStorage.h"

class StorageFactoryCreation
{
public:
    static std::unique_ptr<IStorage> createStorage(const std::string &type);
};