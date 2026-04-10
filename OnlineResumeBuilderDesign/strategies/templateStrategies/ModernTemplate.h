#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/ITemplateInterface.h"

using namespace std;

class ModernTemplate : public ITemplateInterface
{
public:
    void render(Resume &resume) override
    {
        cout << "---- Modern Template ----\n";
        resume.render();
    }
};