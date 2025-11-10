#ifndef RECIPE_H
#define RECIPE_H

#include <qobject.h>

class Recipe
{
private:
    //sum of all fields must be less or equal = 250
    QString name = 0;
    unsigned int water = 0;
    unsigned int milk = 0;
    unsigned int coffee = 0;
    unsigned int sugar = 0;
    unsigned int vanillaSugar = 0;
    unsigned int cinnamon = 0;

public:
    Recipe(QString name, unsigned int coffee = 0, unsigned int milk = 0,unsigned int water = 0,unsigned int sugar = 0,unsigned int vanillaSugar = 0,unsigned int cinnamon = 0);
    QString getName() const;
    int getWater() const;
    int getMilk() const;
    int getCoffee() const;
    int getSugar() const;
    int getVanillaSugar() const;
    int getCinnamon() const;
};

#endif // RECIPE_H
