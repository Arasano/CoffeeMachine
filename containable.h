#ifndef CONTAINABLE_H
#define CONTAINABLE_H

#include <memory>
class Ingredient;

class Containable {
public:
    virtual ~Containable() = default;
    virtual void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) = 0;
};
#endif
