#include "waterheater.h"
#include "concreteingredients.h"
#include <memory>
#include <stdexcept>

WaterHeater::WaterHeater(QObject* parent)
    : MachinePart("WaterHeater", 25, parent)
{};

void WaterHeater::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Water* waterPtr = dynamic_cast<Water*>(ingredient.get());

    if (waterPtr == nullptr) {
        throw std::invalid_argument("WaterHeater can only process Heatable objects!");
    }

    waterPtr->setTemperature(95.0);
};
