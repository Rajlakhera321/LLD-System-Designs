#pragma once
#include <bits/stdc++.h>
#include "../repositories/LoanRepository.h"
#include "../strategies/FineStrategy.h"
#include "../models/User.h"
#include "../models/BookItem.h"
#include "../factory/PaymentFactory.h"

using namespace std;

class LoanService
{
private:
    LoanRepository *lr;
    FineStrategy *fineStrategy;
    PaymentFactory *paymentFactory;

public:
    LoanService(LoanRepository *repo, FineStrategy *fs, PaymentFactory *pf) : lr(repo), fineStrategy(fs), paymentFactory(pf) {}

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

        string gatewayType = "stripe";
        // cout << "Choose payment gateway (stripe/razorpay): ";
        // cin >> gatewayType;

        auto gateway = paymentFactory->createPaymentGateway(gatewayType);
        if (!gateway)
        {
            cout << "Invalid payment gateway selected!" << endl;
            return fine;
        }

        bool paid = gateway->processPayment(record->getUserId(), fine);

        if (!paid)
            cout << "Payment FAILED\n";
        else
            cout << "Payment SUCCESS\n";

        item->setStatus(BookStatus::AVAILABLE);
        item->notifyNextUser();
        return fine;
    }
};