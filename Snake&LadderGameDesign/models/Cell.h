#pragma once
#include <bits/stdc++.h>
#include "./Jump.h"

using namespace std;

class Cell
{
private:
    int position;
    unique_ptr<Jump> jump;

public:
    Cell(int pos) : position(pos), jump(nullptr) {}

    int getPosition() const { return position; }
    Jump *getJump() const { return jump.get(); }
    void setJump(unique_ptr<Jump> j) { jump = move(j); }
};