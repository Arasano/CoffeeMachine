#include "concreteingredients.h"

#include <stdexcept>

Coffee::Coffee(int portions) : Ingredient("Coffee", IngredientType::EATABLE, portions)  {};
CoffeeStatus Coffee::getCoffeeStatus(){    return this->status;};
void Coffee::setCoffeeStatus(CoffeeStatus status){   this->status = status;};

Water::Water(int portions) : Ingredient("Water", IngredientType::EATABLE, portions) {};

Milk::Milk(int portions) : Ingredient("Milk", IngredientType::EATABLE, portions) {};

Sugar::Sugar(int portions) : Ingredient("Sugar", IngredientType::EATABLE, portions) {};

VanillaSugar::VanillaSugar(int portions) : Ingredient("VanillaSugar", IngredientType::EATABLE, portions)  {};

Cinnamon::Cinnamon(int portions) : Ingredient("Cinnamon", IngredientType::EATABLE, portions)  {};

Cup::Cup() : Ingredient("Сup", IngredientType::NOTEATABLE)  {};
Coffee* Cup::getCoffee() const{    return coffee.get();}
void Cup::setCoffee(std::unique_ptr<Ingredient> newCoffee){
    Coffee* ptr = dynamic_cast<Coffee*>(newCoffee.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup setCoffee can only process specific objects!");
    }
    newCoffee.release();
    coffee = std::unique_ptr<Coffee>(ptr);
}
Water*Cup::getWater() const{    return water.get();}
void Cup::setWater(std::unique_ptr<Ingredient> newWater){
    Water* ptr = dynamic_cast<Water*>(newWater.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup setWater can only process specific objects!");
    }
    newWater.release();
    water = std::unique_ptr<Water>(ptr);
}
Milk*Cup::getMilk() const{    return milk.get();}
void Cup::setMilk(std::unique_ptr<Ingredient> newMilk){
    Milk* ptr = dynamic_cast<Milk*>(newMilk.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup setMilk can only process specific objects!");
    }
    newMilk.release();
    milk = std::unique_ptr<Milk>(ptr);
}
Sugar*Cup::getSugar() const{    return sugar.get();}
void Cup::setSugar(std::unique_ptr<Ingredient> newSugar){
    Sugar* ptr = dynamic_cast<Sugar*>(newSugar.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup getSugar can only process specific objects!");
    }
    newSugar.release();
    sugar = std::unique_ptr<Sugar>(ptr);
}
VanillaSugar*Cup::getVanillaSugar() const{    return vanillaSugar.get();}
void Cup::setVanillaSugar(std::unique_ptr<Ingredient> newVanillaSugar){
    VanillaSugar* ptr = dynamic_cast<VanillaSugar*>(newVanillaSugar.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup getVanillaSugar can only process specific objects!");
    }
    newVanillaSugar.release();
    vanillaSugar = std::unique_ptr<VanillaSugar>(ptr);
}
Cinnamon*Cup::getCinnamon() const{    return cinnamon.get();}
void Cup::setCinnamon(std::unique_ptr<Ingredient> newCinnamon){
    Cinnamon* ptr = dynamic_cast<Cinnamon*>(newCinnamon.get());

    if (ptr == nullptr) {
        throw std::invalid_argument("Cup setCinnamon can only process specific objects!");
    }
    newCinnamon.release();
    cinnamon = std::unique_ptr<Cinnamon>(ptr);
}
