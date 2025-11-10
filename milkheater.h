#ifndef MILKHEATER_H
#define MILKHEATER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class MilkHeater : public MachinePart, public Convertible {
    Q_OBJECT
public:
    explicit MilkHeater(QObject* parent = nullptr);
    void convertIngredient(std::unique_ptr<Ingredient>& ingredient) override;
};

#endif // MILKHEATER_H
