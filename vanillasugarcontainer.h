#ifndef VANILLASUGARCONTAINER_H
#define VANILLASUGARCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class VanillaSugarContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit VanillaSugarContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};

#endif // VANILLASUGARCONTAINER_H
