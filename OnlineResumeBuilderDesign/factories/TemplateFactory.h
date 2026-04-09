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
    unique_ptr<ITemplateInterface> createTemplate(const string &type)
    {
        if (type == 'modern')
            return new ModernTemplate();
        else if (type == 'classic')
            return new ClassicTemplate();
        else if (type == 'minimal')
            return new MinimalTemplate();
    }
};