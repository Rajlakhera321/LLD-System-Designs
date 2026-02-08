#pragma once
#include <bits/stdc++.h>
#include "User.h"
#include "Book.h"

using namespace std;

class LoanRecord
{
private:
    int userId;
    int copyId;
    string borrowDate;
    string amountDue;
    string dueDate;
    string returnDate;
    int fineAmount = 0;

public:
    LoanRecord(int u, int b, string borrow, string dd) : userId(u), copyId(b), borrowDate(borrow), dueDate(dd), returnDate("") {}

    int getCopyId() const { return copyId; }
    int getUserId() const { return userId; }

    string getReturnDate() const { return returnDate; }

    string getBorrowedDate() const { return borrowDate; }

    void setFine(int f) { fineAmount = f; }

    void setReturnDate(string r)
    {
        returnDate = r;
    }

    bool isReturned() const { return returnDate != ""; }
};