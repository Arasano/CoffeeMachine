#include "beancontainer.h"

#include "beancontainer.h"
#include "concreteingredients.h"
#include <memory>

BeanContainer::BeanContainer(QObject* parent)
    : MachinePart("BeanContainer", 2, parent)
{};

void BeanContainer::getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) {
    startWork(this->getPreparationTime());
    ingredientHolder.release();
    ingredientHolder = std::make_unique<Coffee>(portions);
};
