#pragma once
#include <bits/stdc++.h>
#include "../interfaces/Section.h"
#include "../structs/SummaryDto.h"

using namespace std;

class Summary : public Section
{
private:
    string summaryText;

public:
    Summary(const string &text) : summaryText(text) {}

    SectionType getType() override
    {
        return SectionType::SUMMARY;
    }

    void update(void *data) override
    {
        SummaryDto *dto = static_cast<SummaryDto *>(data);

        summaryText = dto->summary;
    }

    void render() override
    {
        cout << "Summary: " << summaryText << endl;
    }
};