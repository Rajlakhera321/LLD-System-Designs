#pragma once
#include <bits/stdc++.h>
#include "../models/LoanRecord.h"

using namespace std;

class LoanRepository
{
public:
    vector<LoanRecord *> loans;

    void add(LoanRecord *lr) { loans.push_back(lr); }

    LoanRecord *activeLoan(int copyId)
    {
        for (auto r : loans)
            if (r->getCopyId() == copyId && r->getReturnDate() == "")
                return r;
        return nullptr;
    }
};