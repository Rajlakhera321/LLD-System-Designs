#pragma once
#include <bits/stdc++.h>
#include "../repositories/LoanRepository.h"
#include "../strategies/FineStrategy.h"
#include "../models/User.h"
#include "../models/BookItem.h"

using namespace std;

class LoanService
{
private:
    LoanRepository *lr;
    FineStrategy *fineStrategy;

public:
    LoanService(LoanRepository *repo, FineStrategy *fs) : lr(repo), fineStrategy(fs) {}

    bool borrow(User *u, BookItem *item)
    {
        if (!item || item->getBookStatus() != BookStatus::AVAILABLE)
            return false;

        LoanRecord *r = new LoanRecord(u->getId(), item->getCopyId(), "2026-02-07", "2026-02-14");
        lr->add(r);

        item->setStatus(BookStatus::BORROWED);
        u->addToHistory(item->getCopyId());
        return true;
    }

    int returnBook(BookItem *item)
    {
        auto record = lr->activeLoan(item->getCopyId());
        if (!record)
            return 0;

        record->setReturnDate("2026-02-20");
        int daysLate = 6; // simulated
        int fine = fineStrategy->calculateFine(daysLate);
        record->setFine(fine);

        item->setStatus(BookStatus::AVAILABLE);
        item->notifyNextUser();
        return fine;
    }
};