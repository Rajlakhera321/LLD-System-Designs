#pragma once
#include <bits/stdc++.h>
#include "IDGenerator.h"

using namespace std;

class Book
{
private:
    string name;
    int id;
    string author;

public:
    Book(std::string n, std::string a) : name(n), author(a)
    {
        id = IDGenerator::generateBookId();
    }

    std::string getName() const
    {
        return name;
    }

    int getId() const
    {
        return id;
    }

    string getAuthor() const
    {
        return author;
    }
};