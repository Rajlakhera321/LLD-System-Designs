#pragma once

#include "bits/stdc++.h"
#include "../interfaces/ISearch.h"
#include "../interfaces/IStorage.h"

class NameSearch : public ISearch
{
private:
    IStorage *storage;

public:
    NameSearch(IStorage *storage) : storage(storage) {}
    std::vector<std::string> search(const std::string &query) override;
};