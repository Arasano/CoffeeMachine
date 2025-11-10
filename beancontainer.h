#ifndef BEANCONTAINER_H
#define BEANCONTAINER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class BeanContainer : public MachinePart, public Containable {
    Q_OBJECT

public:
    explicit BeanContainer(QObject* parent = nullptr);
    void getIngredient(std::unique_ptr<Ingredient>& ingredientHolder, int portions) override;
};

#endif // BEANCONTAINER_H
