#include "coffeebrewer.h"
#include "concreteingredients.h"
#include <memory>

CoffeeBrewer::CoffeeBrewer(QObject* parent)
    : MachinePart("CoffeeBrewer", 20, parent)
{};

void CoffeeBrewer::createCoffeeCup(std::unique_ptr<Ingredient> coffee,
                                   std::unique_ptr<Ingredient> water,
                                   std::unique_ptr<Ingredient> milk,
                                   std::unique_ptr<Ingredient> sugar,
                                   std::unique_ptr<Ingredient> vanillaSugar,
                                   std::unique_ptr<Ingredient> cinnamon,
                                   Ingredient& cup)
{
    startWork(this->getPreparationTime());

    try {
        Cup& cupRef = dynamic_cast<Cup&>(cup); // бросает исключение при ошибке
        cupRef.setCoffee(std::move(coffee));
        cupRef.setWater(std::move(water));
        cupRef.setMilk(std::move(milk));
        cupRef.setSugar(std::move(sugar));
        cupRef.setVanillaSugar(std::move(vanillaSugar));
        cupRef.setCinnamon(std::move(cinnamon));
    }
    catch (const std::bad_cast& e) {
    }
};
