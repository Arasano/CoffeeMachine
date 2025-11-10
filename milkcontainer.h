#ifndef MILKCONTAINER_H
#define MILKCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class MilkContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit MilkContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};
#endif // MILKCONTAINER_H
