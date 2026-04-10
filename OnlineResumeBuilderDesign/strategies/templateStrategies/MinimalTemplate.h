#pragma once
#include <bits/stdc++.h>
#include "../../interfaces/ITemplateInterface.h"

using namespace std;

class MinimalTemplate : public ITemplateInterface
{
public:
    void render(Resume &resume) override
    {
        cout << "---- Minimal Template ----\n";
        resume.render();
    }
};