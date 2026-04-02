#pragma once
#include <bits/stdc++.h>
#include "./Jump.h"

using namespace std;

class Cell
{
private:
    int position;
    Jump *jump;

public:
    Cell(int pos) : position(pos), jump(nullptr) {}

    int getPosition() const { return position; }
    Jump *getJump() const { return jump; }
    void setJump(Jump *j) { jump = j; }
};