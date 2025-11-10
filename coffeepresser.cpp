#include "coffeepresser.h"
#include "concreteingredients.h"
#include <memory>

CoffeePresser::CoffeePresser(QObject* parent)
    : MachinePart("CoffeePresser", 10, parent)
{};

void CoffeePresser::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Coffee* coffeePtr = dynamic_cast<Coffee*>(ingredient.get());

    if (coffeePtr == nullptr) {
        throw std::invalid_argument("CoffeePresser can only process Coffee objects!");
    }

    coffeePtr->setCoffeeStatus(CoffeeStatus::PRESSED);
};

