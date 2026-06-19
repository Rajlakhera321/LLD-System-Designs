#pragma once

#include "bits/stdc++.h"
#include "../models/Folder.h"

class DriveService
{
private:
    std : shared_ptr<Folder> root;

public:
    void upload(const std::string &path, const std::string &content);
    void download(const std::string &path);
};