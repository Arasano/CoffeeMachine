#ifndef COFFEEGRINDER_H
#define COFFEEGRINDER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class CoffeeGrinder : public MachinePart, public Convertible {
    Q_OBJECT
public:
    explicit CoffeeGrinder(QObject* parent = nullptr);
    void convertIngredient(std::unique_ptr<Ingredient>& ingredient) override;
};

#endif // COFFEEGRINDER_H
