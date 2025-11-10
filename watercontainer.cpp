#include "watercontainer.h"
#include "concreteingredients.h"
#include <memory>

WaterContainer::WaterContainer(QObject* parent)
    : MachinePart("WaterContainer", 2, parent)
{};

void WaterContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Water>(portions);
};

