#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/IExportInterface.h"

using namespace std;

class PdfStrategy : public IExportInterface
{
public:
    void exportFile() override
    {
        cout << "Downloading resume as pdf";
    }
};