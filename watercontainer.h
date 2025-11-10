#ifndef WATERCONTAINER_H
#define WATERCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class WaterContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit WaterContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};


#endif // WATERCONTAINER_H
