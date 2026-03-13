#pragma once
#include <bits/stdc++.h>
#include "../repositories/InventoryRepository.h"

using namespace std;

class InventoryService
{
private:
    InventoryRepository repository;

public:
    InventoryService();
    bool isItemAvailable(const string &item);
    void updateInventory(const string &item, int quantity);
};