#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"

using namespace std;

class Summary : public Section
{
private:
    string summaryText;

public:
    Summary(const string &text) : summaryText(text) {}

    void render() override
    {
        cout << "Summary: " << summaryText << endl;
    }
};