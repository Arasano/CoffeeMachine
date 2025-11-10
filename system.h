#ifndef SYSTEM_H
#define SYSTEM_H

#include "Ingredient.h"
#include "beancontainer.h"
#include "coffeebrewer.h"
#include "coffeegrinder.h"
#include "coffeepresser.h"
#include "milkcontainer.h"
#include "milkheater.h"
#include "watercontainer.h"
#include "sugarcontainer.h"
#include "vanillasugarcontainer.h"
#include "cinnamoncontainer.h"
#include "cupcontainer.h"
#include "recipe.h"
#include "waterheater.h"
#include <memory>
#include <QThread>
#include <QTimer>
#include <QObject>
#include <QMap>

class System: public QObject {
    Q_OBJECT

public:
    System(std::unique_ptr<Recipe> recipe);
    ~System();

    int getTimeTotal() const;
    void setTimeTotal(int newTimeTotal);
    int getTimeLeft() const;
    void setTimeLeft(int newTimeLeft);

    QString getRecipeName() const;

    int calculateTime();
    void startProcess();
    void cancelProcess();

signals:
    void deviceProgress(const QString& deviceName, int timeLeft, int totalTime);
    void deviceStarted(const QString& deviceName);
    void deviceFinished(const QString& deviceName);
    void processCompleted();
    void processCancelled();

private slots:
    void onDeviceProgress(const QString& deviceName, int timeLeft, int totalTime);
    void onDeviceFinished(const QString& deviceName);
    void onDeviceStarted(const QString& deviceName);
    void updateDebugInfo();

private:
    void setupDevices();
    void connectDeviceSignals(MachinePart* device);
    void checkProcessCompletion();
    void executeBrewing();

    void executeCoffee();
    void executeMilk();
    void executeWater();
    void executeSugar();
    void executeVanillaSugar();
    void executeCinnamon();
    void executeCup();

    int timeTotal;
    int timeLeft;
    std::unique_ptr<Recipe> recipe;

    std::unique_ptr<Ingredient> coffee;
    std::unique_ptr<Ingredient> water;
    std::unique_ptr<Ingredient> milk;
    std::unique_ptr<Ingredient> sugar;
    std::unique_ptr<Ingredient> vanillaSugar;
    std::unique_ptr<Ingredient> cinnamon;
    std::unique_ptr<Ingredient> cup;

    std::unique_ptr<BeanContainer> beanContainer;
    std::unique_ptr<WaterContainer> waterContainer;
    std::unique_ptr<MilkContainer> milkContainer;
    std::unique_ptr<SugarContainer> sugarContainer;
    std::unique_ptr<VanillaSugarContainer> vanillaSugarContainer;
    std::unique_ptr<CinnamonContainer> cinnamonContainer;
    std::unique_ptr<CupContainer> cupContainer;
    std::unique_ptr<MilkHeater> milkHeater;
    std::unique_ptr<WaterHeater> waterHeater;
    std::unique_ptr<CoffeeGrinder> coffeeGrinder;
    std::unique_ptr<CoffeePresser> coffeePresser;
    std::unique_ptr<CoffeeBrewer> coffeeBrewer;

    QMap<QString, MachinePart*> m_activeDevices;
    QMap<QString, bool> m_deviceCompleted;
    int m_completedDevices;
    int m_totalDevices;
    bool m_processRunning;
    QTimer* m_debugTimer;
};

#endif // SYSTEM_H
