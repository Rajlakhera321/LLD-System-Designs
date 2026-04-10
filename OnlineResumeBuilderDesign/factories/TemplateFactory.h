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
    static unique_ptr<ITemplateInterface> createTemplate(const string &type)
    {
        if (type == "modern")
            return make_unique<ModernTemplate>();
        else if (type == "classic")
            return make_unique<ClassicTemplate>();
        else if (type == "minimal")
            return make_unique<MinimalTemplate>();

        return nullptr;
    }
};