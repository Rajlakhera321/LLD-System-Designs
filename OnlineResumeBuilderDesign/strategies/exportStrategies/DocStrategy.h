#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IExportInterface.h"

using namespace std;

class DocStrategy : public IExportInterface
{
public:
    void exportFile() override
    {
        cout << "Downloading resume as Doc";
    }
};