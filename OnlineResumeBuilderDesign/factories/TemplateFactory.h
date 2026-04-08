#pragma once
#include <bits/stdc++.h>
#include "../interfaces/ITemplateInterface.h"
#include "../strategies/templateStrategies/ModernTemplate.h"
#include "../strategies/templateStrategies/ClassicTemplate.h"
#include "../strategies/templateStrategies/MinimalTemplate.h"

using namespace std;

class TemplateFactory
{
public:
    ITemplateInterface createTemplate(const string &type)
    {
        switch (type)
        {
        case "modern":
            return new ModernTemplate();
        case "classic":
            return new ClassicTemplate();
        case "minimal":
            return new MinimalTemplate();
        default:
            return nullptr;
        }
    }
};