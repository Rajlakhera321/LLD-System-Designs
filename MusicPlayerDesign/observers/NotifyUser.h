#pragma once
#include <bits/stdc++.h>
#include "../interfaces/IObserver.h"

using namespace std;

class NotifyUser : public IObserver
{
public:
    void notify(const string message) override;
};