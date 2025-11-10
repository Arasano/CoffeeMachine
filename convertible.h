#ifndef CONVERTIBLE_H
#define CONVERTIBLE_H

#include <memory>
class Ingredient;

class Convertible {
public:
    virtual ~Convertible() = default;
    virtual void convertIngredient(std::unique_ptr<Ingredient>& ingredient) = 0;
};
#endif
