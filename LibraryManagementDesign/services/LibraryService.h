#pragma once
#include <bits/stdc++.h>
#include "../repositories/BookRepository.h"
#include "../repositories/UserRepository.h"
#include "ReservationService.h"
#include "LoanService.h"

class LibraryService
{
private:
    BookRepository *bookRepo;
    UserRepository *userRepo;
    LoanService *loanService;
    ReservationService *reservationService;

public:
    LibraryService(BookRepository *b, UserRepository *u, LoanService *l)
        : bookRepo(b), userRepo(u), loanService(l) {}
    void addBook(Book *b, int copies)
    {
        bookRepo->addBook(b);
        for (int i = 0; i < copies; i++)
            bookRepo->addCopy(new BookItem(b, userRepo));
    }

    void addUser(User *u)
    {
        userRepo->add(u);
    }

    bool borrowBook(int userId, const std::string &bookName)
    {
        User *user = userRepo->findById(userId);
        if (!user)
            return false;

        auto available = bookRepo->findAvailableCopies(bookName);

        if (available.empty())
        {
            BookItem *firstCopy = bookRepo->copies[0];
            reservationService->reserveBook(user, firstCopy);
            return false;
        }

        return loanService->borrow(user, available[0]);
    }
    int returnBook(int copyId)
    {
        BookItem *item = bookRepo->findCopyById(copyId);
        if (!item)
            return 0;

        return loanService->returnBook(item);
    }
    Book *searchBookById(int bookId)
    {
        return bookRepo->findBookById(bookId);
    }

    Book *searchBookByName(const std::string &title)
    {
        return bookRepo->findBookByTitle(title);
    }

    User *searchUserByName(std::string userName)
    {
        return userRepo->findByName(userName);
    }
};