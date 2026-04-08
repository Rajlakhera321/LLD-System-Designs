#pragma once
#include <bits/stdc++.h>

using namespace std;

class IExportInterface
{
public:
    virtual void exportFile() = 0;
    virtual ~IExportInterface() {};
};