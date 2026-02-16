#pragma once
#include <bits/stdc++.h>

using namespace std;

class Door
{
private:
    bool isOpen = false;

public:
    void open() { isOpen = true; }

    void close() { isOpen = false; }

    bool isOpened()
    {
        return isOpen;
    }
};