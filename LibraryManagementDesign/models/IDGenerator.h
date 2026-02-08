#pragma once
#include <bits/stdc++.h>

class IDGenerator
{
public:
    static int bookId;
    static int copyId;
    static int userId;

    static int generateBookId() { return ++bookId; }
    static int generateUserId() { return ++userId; }
    static int generateCopyId() { return ++copyId; }
};

int IDGenerator::bookId = 0;
int IDGenerator::copyId = 0;
int IDGenerator::userId = 0;