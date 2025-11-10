#ifndef CINNAMONCONTAINER_H
#define CINNAMONCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class CinnamonContainer : public MachinePart, public Containable {
    Q_OBJECT
public:
    explicit CinnamonContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};

#endif // CINNAMONCONTAINER_H
