#pragma once

#include "bits/stdc++.h"

class DriveService
{
public:
    void upload(const std::string &path, const std::string &content);
    void download(const std::string &path);
};