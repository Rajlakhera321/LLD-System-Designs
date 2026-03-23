#include "controllers/CoffeeMachineController.h"
#include "enums/BeverageEnum.h"
#include "enums/IngredientEnum.h"

int main()
{

    CoffeeMachineController controller;

    // Refill inventory
    controller.refill(IngredientEnum::CoffeeBeans, 100);
    controller.refill(IngredientEnum::Milk, 100);
    controller.refill(IngredientEnum::Water, 200);

    // Make beverages
    controller.makeBeverage(BeverageEnum::Espresso);
    controller.makeBeverage(BeverageEnum::Latte);

    return 0;
}