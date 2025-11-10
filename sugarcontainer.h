#ifndef SUGARCONTAINER_H
#define SUGARCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class SugarContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit SugarContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};

#endif // SUGARCONTAINER_H
