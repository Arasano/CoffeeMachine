#ifndef WATERHEATER_H
#define WATERHEATER_H

#include "machinepart.h"
#include "containable.h"
#include "convertible.h"

class WaterHeater : public MachinePart, public Convertible {
    Q_OBJECT
public:
    explicit WaterHeater(QObject* parent = nullptr);
    void convertIngredient(std::unique_ptr<Ingredient>& ingredient) override;
};

#endif // WATERHEATER_H
