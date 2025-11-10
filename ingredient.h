// Ingredient.h
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <qobject.h>

enum class IngredientType {
    EATABLE,
    NOTEATABLE
};

class Ingredient {
protected:
    QString name;
    int portions;
    IngredientType type;

public:
    Ingredient(const QString& name, IngredientType type, int portions = 1);
    virtual ~Ingredient() = default;

    QString getName() const;
    IngredientType getType() const;
    int getPortions() const;
    void setPortions(int p);
};

#endif
