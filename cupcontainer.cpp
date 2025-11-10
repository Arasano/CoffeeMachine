#include "cupcontainer.h"
#include "concreteingredients.h"
#include <memory>

CupContainer::CupContainer(QObject* parent)
    : MachinePart("CupContainer", 2, parent)
{};

void CupContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder,int portions)
{
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Cup>();
};
