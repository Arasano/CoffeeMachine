#include "milkheater.h"
#include "concreteingredients.h"
#include <memory>
#include <stdexcept>

MilkHeater::MilkHeater(QObject* parent)
    : MachinePart("MilkHeater", 21, parent)
{};

void MilkHeater::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Milk* milkPtr = dynamic_cast<Milk*>(ingredient.get());

    if (milkPtr == nullptr) {
        throw std::invalid_argument("MilkHeater can only process Heatable objects!");
    }

    milkPtr->setTemperature(65.0);
};

