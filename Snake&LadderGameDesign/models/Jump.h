#pragma once

class Jump
{
private:
    int start;
    int end;

public:
    Jump(int s, int e) : start(s), end(e) {}

    int getStart() const { return start; }
    int getEnd() const { return end; }
};