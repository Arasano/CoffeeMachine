#include "sugarcontainer.h"
#include "concreteingredients.h"
#include <memory>

SugarContainer::SugarContainer(QObject* parent)
    : MachinePart("SugarContainer", 2, parent)
{};

void SugarContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Sugar>(portions);
};
