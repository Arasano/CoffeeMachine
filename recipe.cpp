#include "recipe.h"
#include <stdexcept>

QString Recipe::getName() const{return name;}
int Recipe::getWater() const{return water;}
int Recipe::getMilk() const{return milk;}
int Recipe::getCoffee() const{return coffee;}
int Recipe::getSugar() const{    return sugar;}
int Recipe::getVanillaSugar() const{return vanillaSugar;}
int Recipe::getCinnamon() const{return cinnamon;}

Recipe::Recipe(QString name, unsigned int coffee, unsigned int milk, unsigned int water, unsigned int sugar, unsigned int vanillaSugar, unsigned int cinnamon){
    this->name = name;

    if((water + milk + coffee + sugar + vanillaSugar + cinnamon) <= 250){
        this->water = water;
        this->milk = milk;
        this->coffee = coffee;
        this->sugar = sugar;
        this->vanillaSugar = vanillaSugar;
        this->cinnamon = cinnamon;
    }else{
        throw std::runtime_error("sum of all fields in Recipe more then 250");
    }

};

