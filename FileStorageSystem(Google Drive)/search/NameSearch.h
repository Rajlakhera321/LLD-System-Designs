#pragma once

#include "bits/stdc++.h"
#include "../interfaces/ISearch.h"
#include "../models/Folder.h"
#include "../interfaces/IDriveItems.h"

class NameSearch : public ISearch
{
public:
    std::vector<shared_ptr<IDriveItems> > search(shared_ptr<Folder> root, const std::string &query) override;
    
};