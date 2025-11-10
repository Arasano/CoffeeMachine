#include "ingredient.h"

Ingredient::Ingredient(const QString& name, IngredientType type, int portions) {
    this->portions = portions;
    this->name = name;
    this->type = type;
}

QString Ingredient::getName() const{
    return this->name;
}
IngredientType Ingredient::getType() const{
    return this->type;
}
int Ingredient::getPortions() const{
    return this->portions;
}
void Ingredient::setPortions(int p){
    this->portions = p;
}
