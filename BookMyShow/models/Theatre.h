#pragma once
#include <bits/stdc++.h>
#include "IdGenerator.h"

using namespace std;

class Theatre
{
private:
    int theatreId;
    string name;
    string address;

public:
    Theatre(string name, string address) : name(name), address(address)
    {
        theatreId = IdGenerator::generateThreatreId();
    }

    string getThreatreName() const { return name; }

    string getThreatreAddress() const { return address; }
    int getThreatreId() const { return theatreId; }
};