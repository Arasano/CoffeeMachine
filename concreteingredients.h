// ConcreteIngredients.h
#ifndef CONCRETEINGREDIENTS_H
#define CONCRETEINGREDIENTS_H

#include "Ingredient.h"
#include "heatable.h"
#include <memory>

enum class CoffeeStatus {
    BEANS,
    POWDER,
    PRESSED
};

class Coffee : public Ingredient {
private:
    CoffeeStatus status = CoffeeStatus::BEANS;
public:
    Coffee(int portions = 1);
    CoffeeStatus getCoffeeStatus();
    void setCoffeeStatus(CoffeeStatus status);
};

class Water : public Ingredient, public Heatable {
public:
    Water(int portions = 1);
};

class Milk : public Ingredient, public Heatable {
public:
    Milk(int portions = 1);
};

class Sugar : public Ingredient {
public:
    Sugar(int portions = 1);
};

class VanillaSugar : public Ingredient {
public:
    VanillaSugar(int portions = 1);
};

class Cinnamon : public Ingredient {
public:
    Cinnamon(int portions = 1);
};

class Cup : public Ingredient {
private:
    int copacity = 250;//средний стакан величиной 250 мл
    std::unique_ptr<Coffee> coffee;
    std::unique_ptr<Water> water;
    std::unique_ptr<Milk> milk;
    std::unique_ptr<Sugar> sugar;
    std::unique_ptr<VanillaSugar> vanillaSugar;
    std::unique_ptr<Cinnamon> cinnamon;
public:
    Cup();
    int getCopacity() const;
    void setCopacity(int newCopacity);


    Coffee*getCoffee() const;
    void setCoffee(std::unique_ptr<Ingredient> newCoffee);
    Water*getWater() const;
    void setWater(std::unique_ptr<Ingredient> newWater);
    Milk*getMilk() const;
    void setMilk(std::unique_ptr<Ingredient> newMilk);
    Sugar*getSugar() const;
    void setSugar(std::unique_ptr<Ingredient> newSugar);
    VanillaSugar*getVanillaSugar() const;
    void setVanillaSugar(std::unique_ptr<Ingredient> newVanillaSugar);
    Cinnamon*getCinnamon() const;
    void setCinnamon(std::unique_ptr<Ingredient> newCinnamon);
};

#endif
