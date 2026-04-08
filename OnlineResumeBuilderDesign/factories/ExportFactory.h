#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IExportInterface.h"
#include "../strategies/exportStrategies/DocStrategy.h"
#include "../strategies/exportStrategies/PdfStrategy.h"

class ExportFactory
{
public:
    static IExportInterface createExport(const string &type)
    {
        switch (type)
        {
        case "pdf":
            return new PdfStrategy();
        case "doc":
            return new DocStrategy();
        default:
            return nullptr;
        }
    }
};