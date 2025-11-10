#include "concretemachineparts.h"
#include "concreteingredients.h"

#include <memory>
#include <stdexcept>

BeanContainer::BeanContainer(QObject* parent) : MachinePart("BeanContainer", 2), Containable(), Workable("BeanContainer", parent) {};
void BeanContainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<Coffee*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("BeanContainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Coffee>(portions));
};

WaterСontainer::WaterСontainer(QObject* parent) : MachinePart("WaterСontainer", 2), Containable(), Workable("WaterСontainer", parent) {};
void WaterСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<Water*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("WaterСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Water>(portions));
};

MilkСontainer::MilkСontainer(QObject* parent) : MachinePart("MilkСontainer", 2), Containable(), Workable("MilkСontainer", parent) {};
void MilkСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<Milk*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("MilkСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Milk>(portions));
};

SugarСontainer::SugarСontainer(QObject* parent) : MachinePart("SugarСontainer", 2), Containable(), Workable("SugarСontainer", parent) {};
void SugarСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<Sugar*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("SugarСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Sugar>(portions));
};

VanillaSugarСontainer::VanillaSugarСontainer(QObject* parent) : MachinePart("VanillaSugarСontainer", 2), Containable(), Workable("VanillaSugarСontainer", parent) {};
void VanillaSugarСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<VanillaSugar*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("VanillaSugarСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<VanillaSugar>(portions));
};

CinnamonСontainer::CinnamonСontainer(QObject* parent) : MachinePart("CinnamonСontainer", 2), Containable(), Workable("CinnamonСontainer", parent) {};
void CinnamonСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder, int portions) {
    startWork(this->getPreparationTime());
    if (dynamic_cast<Cinnamon*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("CinnamonСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Cinnamon>(portions));
};

CupСontainer::CupСontainer(QObject* parent) : MachinePart("CupСontainer", 2), Containable(), Workable("CupСontainer", parent) {};
void CupСontainer::getIngredient(std::unique_ptr<Ingredient>& ingridientHolder,int portions)
{
    startWork(this->getPreparationTime());
    if (dynamic_cast<Cup*>(ingridientHolder.get()) == nullptr) {
        throw std::invalid_argument("CupСontainer can only process specific objests!");
    }
    ingridientHolder = std::move(std::make_unique<Cup>());
};



MilkHeater::MilkHeater(QObject* parent) : MachinePart("MilkHeater", 21), Convertible(), Workable("MilkHeater", parent) {};
void MilkHeater::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Milk* milkPtr = dynamic_cast<Milk*>(ingredient.get());

    if (milkPtr == nullptr) {
        throw std::invalid_argument("MilkHeater can only process Heatable objests!");
    }

    milkPtr->setTemperature(65.0);
};

WaterHeater::WaterHeater(QObject* parent) : MachinePart("WaterHeater", 25), Convertible(), Workable("WaterHeater", parent) {};
void WaterHeater::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Water* waterPtr = dynamic_cast<Water*>(ingredient.get());

    if (waterPtr == nullptr) {
        throw std::invalid_argument("WaterHeater can only process Heatable objests!");
    }

    waterPtr->setTemperature(95.0);
};



CoffeeGrinder::CoffeeGrinder(QObject* parent) : MachinePart("CoffeeGrinder", 19), Convertible(), Workable("CoffeeGrinder", parent) {};
void CoffeeGrinder::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Coffee* coffeePtr = dynamic_cast<Coffee*>(ingredient.get());

    if (coffeePtr == nullptr) {
        throw std::invalid_argument("CoffeeGrinder can only process Coffee objests!");
    }

    coffeePtr->setCoffeeStatus(CoffeeStatus::POWDER);
};


CoffeePresser::CoffeePresser(QObject* parent) : MachinePart("CoffeePresser", 10), Convertible(), Workable("CoffeePresser", parent) {};
void CoffeePresser::convertIngredient(std::unique_ptr<Ingredient>& ingredient) {
    startWork(this->getPreparationTime());
    Coffee* coffeePtr = dynamic_cast<Coffee*>(ingredient.get());

    if (coffeePtr == nullptr) {
        throw std::invalid_argument("CoffeePresser can only process Coffee objests!");
    }

    coffeePtr->setCoffeeStatus(CoffeeStatus::PRESSED);
};

CoffeeBrewer::CoffeeBrewer(QObject* parent): MachinePart("CoffeeBrewer", 20), Workable("CoffeeBrewer", parent) {};
void CoffeeBrewer::createCoffeeCup(std::unique_ptr<Ingredient> coffee,
                                   std::unique_ptr<Ingredient> water,
                                   std::unique_ptr<Ingredient> milk,
                                   std::unique_ptr<Ingredient> sugar,
                                   std::unique_ptr<Ingredient> vanillaSugar,
                                   std::unique_ptr<Ingredient> cinnamon,
                                   Cup& cup)
{
    startWork(this->getPreparationTime());
    cup.setCoffee(std::move(coffee));
    cup.setWater(std::move(water));
    cup.setMilk(std::move(milk));
    cup.setSugar(std::move(sugar));
    cup.setVanillaSugar(std::move(vanillaSugar));
    cup.setCinnamon(std::move(cinnamon));
};


