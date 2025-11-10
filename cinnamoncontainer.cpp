#include "cinnamoncontainer.h"
#include "concreteingredients.h"
#include <memory>

CinnamonContainer::CinnamonContainer(QObject* parent)
    : MachinePart("CinnamonContainer", 2, parent)
{};

void CinnamonContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Cinnamon>(portions);
};
