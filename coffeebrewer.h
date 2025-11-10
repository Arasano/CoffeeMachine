#ifndef COFFEEBREWER_H
#define COFFEEBREWER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class CoffeeBrewer : public MachinePart {
    Q_OBJECT
public:
    explicit CoffeeBrewer(QObject* parent = nullptr);
    void createCoffeeCup(std::unique_ptr<Ingredient> coffee,
                         std::unique_ptr<Ingredient> water,
                         std::unique_ptr<Ingredient> milk,
                         std::unique_ptr<Ingredient> sugar,
                         std::unique_ptr<Ingredient> vanillaSugar,
                         std::unique_ptr<Ingredient> cinnamon,
                         Ingredient& cup);
};

#endif // COFFEEBREWER_H
