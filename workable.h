#ifndef WORKABLE_H
#define WORKABLE_H

#include <QString>

class Workable {
public:
    virtual ~Workable() = default;

    // Чисто виртуальные методы
    virtual void startWork(int preparationTime) = 0;
    virtual void finishWork() = 0;
    virtual bool isWorking() const = 0;
    virtual QString getName() const = 0;
    virtual void cancelWork() = 0;
};

#endif // WORKABLE_H
