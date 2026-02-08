#pragma once
#include <bits/stdc++.h>
#include "Book.h"
#include "../enums/BookStatus.h"
#include "../repositories/UserRepository.h"
#include "IDGenerator.h"
#include "User.h"

using namespace std;

class BookItem
{
private:
    int copyId;
    Book *baseBook;
    BookStatus status;
    queue<int> reservationQueue;
    UserRepository *userRepo;

public:
    BookItem(Book *book, UserRepository *repo) : baseBook(book), userRepo(repo), status(BookStatus::AVAILABLE)
    {
        copyId = IDGenerator::generateCopyId();
    }

    int getCopyId() const { return copyId; }
    Book *getBaseBook() const { return baseBook; }

    BookStatus getBookStatus() const { return status; }

    void setStatus(BookStatus s) { status = s; }

    void reserve(int userId)
    {
        reservationQueue.push(userId);
    }

    bool hasReservation() const { return !reservationQueue.empty(); }

    int nextInQueue()
    {
        int id = reservationQueue.front();
        reservationQueue.pop();
        return id;
    }

    void notifyNextUser()
    {
        if (!reservationQueue.empty())
        {
            int userId = reservationQueue.front();
            reservationQueue.pop();
            User *user = userRepo->findById(userId);

            user->notify("Your reserved book '" + baseBook->getName() + "' is now available!");
        }
    }
};