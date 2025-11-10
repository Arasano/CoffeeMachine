#ifndef COFFEEPRESSER_H
#define COFFEEPRESSER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class CoffeePresser : public MachinePart, public Convertible {
    Q_OBJECT
public:
    explicit CoffeePresser(QObject* parent = nullptr);
    void convertIngredient(std::unique_ptr<Ingredient>& ingredient) override;
};

#endif // COFFEEPRESSER_H
