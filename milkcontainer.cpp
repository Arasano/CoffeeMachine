#include "milkcontainer.h"
#include "concreteingredients.h"
#include <memory>

MilkContainer::MilkContainer(QObject* parent)
    : MachinePart("MilkContainer", 2, parent)
{};

void MilkContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Milk>(portions);
};


