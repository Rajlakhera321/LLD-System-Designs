#pragma once

using namespace std;
#include "../repositories/UserRepository.h"
#include "../repositories/BookRepository.h"
#include "../models/BookItem.h"

class ReservationService
{
private:
    BookRepository *bookRepo;
    UserRepository *userRepo;

public:
    ReservationService(BookRepository *b, UserRepository *u)
        : bookRepo(b), userRepo(u) {}

    void reserveBook(User *user, BookItem *item)
    {
        item->reserve(user->getId());
        user->notify("Book '" + item->getBaseBook()->getName() + "' is currently unavailable. You are placed in queue.");
    }

    void notifyNext(BookItem *item)
    {
        item->notifyNextUser();
    }
};
