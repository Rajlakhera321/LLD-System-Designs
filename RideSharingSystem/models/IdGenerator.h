#pragma once
#include <bits/stdc++.h>

using namespace std;

class IdGenerator
{
public:
    static int userId;

    static int generateUserId() { return ++userId; }
};

int IdGenerator::userId = 0;