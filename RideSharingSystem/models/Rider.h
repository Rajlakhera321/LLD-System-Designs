#pragma once
#include <bits/stdc++.h>
#include "User.h"

using namespace std;

class Rider : public User
{
private:
    double rating;

public:
    Rider(string name, string phone) : User(name, phone), rating(5.0) {}

    double getRating() const { return rating; }
    void updateRating(double r) { rating = r; }
};