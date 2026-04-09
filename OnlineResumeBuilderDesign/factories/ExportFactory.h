#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IExportInterface.h"
#include "../strategies/exportStrategies/DocStrategy.h"
#include "../strategies/exportStrategies/PdfStrategy.h"

class ExportFactory
{
public:
    unique_ptr<IExportInterface> createExport(const string &type)
    {
        if (type == 'pdf')
            return unique_ptr<PdfStrategy>();
        else if (type == 'doc')
            return unique_ptr<DocStrategy>();
        else
            return nullptr;
    }
};