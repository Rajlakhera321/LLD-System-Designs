#pragma once
#include "bits/stdc++.h"
#include "../interfaces/IStorage.h"
#include "../storages/DBStorage.h"
#include "../storages/RedisStorage.h"

class StorageFactoryCreation
{
public:
    static IStorage *createStorage(const std::string &type);
};