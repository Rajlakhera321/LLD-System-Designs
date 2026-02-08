#pragma once
#include <bits/stdc++.h>
#include "../models/Book.h"
#include "../models/BookItem.h"

using namespace std;

class BookRepository
{
public:
    vector<Book *> books;
    vector<BookItem *> copies;

    void addBook(Book *b) { books.push_back(b); }
    void addCopy(BookItem *c) { copies.push_back(c); }

    vector<BookItem *> findAvailableCopies(string name)
    {
        vector<BookItem *> res;
        for (auto c : copies)
        {
            if (c->getBaseBook()->getName() == name &&
                c->getBookStatus() == BookStatus::AVAILABLE)
            {
                res.push_back(c);
            }
        }
        return res;
    }

    BookItem *findCopyById(int id)
    {
        for (auto c : copies)
            if (c->getCopyId() == id)
                return c;

        return nullptr;
    }

    Book *findBookById(int id)
    {
        for (auto b : books)
        {
            if (b->getId() == id)
                return b;
        }
        return NULL;
    }

    Book *findBookByTitle(string title)
    {
        for (auto b : books)
        {
            if (b->getName() == title)
                return b;
        }
        return NULL;
    }
};