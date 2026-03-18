#include "bits/stdc++.h"
#include "enums/BeverageEnum.h"
#include "enums/IngredientEnum.h"
#include "services/BeverageService.h"
#include "services/InventoryService.h"
#include "repositories/BeverageRepository.h"
#include "repositories/InventoryRepository.h"
#include "controllers/CoffeeMachineController.h"

using namespace std;

int main()
{
    BeverageRepository beverageRepo;
    InventoryRepository inventoryRepo;

    BeverageService beverageService(&beverageRepo);
    InventoryService inventoryService;

    CoffeeMachineController controller(beverageService, inventoryService);

    // Add some beverages
    beverageService.addBeverage(new Beverage(BeverageEnum::Espresso, {IngredientEnum::CoffeeBeans, IngredientEnum::Water}));
    beverageService.addBeverage(new Beverage(BeverageEnum::Latte, {IngredientEnum::CoffeeBeans, IngredientEnum::Milk, IngredientEnum::Water}));
    beverageService.addBeverage(new Beverage(BeverageEnum::Cappuccino, {IngredientEnum::CoffeeBeans, IngredientEnum::Milk, IngredientEnum::Sugar, IngredientEnum::Water}));
    beverageService.addBeverage(new Beverage(BeverageEnum::Mocha, {IngredientEnum::CoffeeBeans, IngredientEnum::Milk, IngredientEnum::ChocolateSyrup, IngredientEnum::Water}));

    // Add some inventory
    inventoryService.updateInventory(IngredientEnum::CoffeeBeans, 100);
    inventoryService.updateInventory(IngredientEnum::Milk, 50);
    inventoryService.updateInventory(IngredientEnum::Sugar, 30);
    inventoryService.updateInventory(IngredientEnum::Water, 200);
    inventoryService.updateInventory(IngredientEnum::ChocolateSyrup, 20);

    // Make some beverages
    controller.makeBeverage(BeverageEnum::Espresso);

    return 0;
}