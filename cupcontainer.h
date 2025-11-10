#ifndef CUPCONTAINER_H
#define CUPCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class CupContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit CupContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};

#endif // CUPCONTAINER_H
