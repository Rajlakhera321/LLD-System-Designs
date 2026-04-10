#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IExportInterface.h"
#include "../strategies/exportStrategies/DocStrategy.h"
#include "../strategies/exportStrategies/PdfStrategy.h"

class ExportFactory
{
public:
    static unique_ptr<IExportInterface> createExport(const string &type)
    {
        if (type == "pdf")
            return make_unique<PdfStrategy>();
        else if (type == "doc")
            return make_unique<DocStrategy>();
        else
            return nullptr;
    }
};