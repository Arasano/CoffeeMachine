#include "vanillasugarcontainer.h"
#include "concreteingredients.h"
#include <memory>

VanillaSugarContainer::VanillaSugarContainer(QObject* parent)
    : MachinePart("VanillaSugarContainer", 2, parent)
{};

void VanillaSugarContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<VanillaSugar>(portions);
};
