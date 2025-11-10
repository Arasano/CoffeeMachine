#include "coffeegrinder.h"
#include "concreteingredients.h"
#include <memory>

CoffeeGrinder::CoffeeGrinder(QObject* parent)
    : MachinePart("CoffeeGrinder", 19, parent)
{};

void CoffeeGrinder::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Coffee* coffeePtr = dynamic_cast<Coffee*>(ingredient.get());

    if (coffeePtr == nullptr) {
        throw std::invalid_argument("CoffeeGrinder can only process Coffee objects!");
    }

    coffeePtr->setCoffeeStatus(CoffeeStatus::POWDER);
};
