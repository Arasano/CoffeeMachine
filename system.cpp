#include <iostream>
#include <memory>
#include <algorithm>
#include <QDebug>
#include <QTimer>
#include <ostream>

#include "system.h"
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
#include "concreteingredients.h"
#include "cupcontainer.h"
#include "recipe.h"
#include "waterheater.h"

int System::getTimeTotal() const { return timeTotal; }
void System::setTimeTotal(int newTimeTotal) { timeTotal = newTimeTotal; }

int System::getTimeLeft() const { return timeLeft; }
void System::setTimeLeft(int newTimeLeft) { timeLeft = newTimeLeft; }

QString System::getRecipeName() const {
    return recipe ? recipe->getName() : "No Recipe";
}

System::System(std::unique_ptr<Recipe> recipe): recipe(std::move(recipe)),
    timeTotal(0),
    timeLeft(0),
    m_completedDevices(0),
    m_totalDevices(0),
    m_processRunning(false),
    m_debugTimer(new QTimer(this))
{
    setupDevices();
    connect(m_debugTimer, &QTimer::timeout, this, &System::updateDebugInfo);
}

System::~System() {
    if (m_debugTimer && m_debugTimer->isActive()) {
        m_debugTimer->stop();
    }
}

void System::updateDebugInfo() {
    if (!m_processRunning) return;

    if (timeLeft % 5 == 0) {
        std::cout << "Time left: " << timeLeft << "s | Completed: "<< m_completedDevices << "/" << m_totalDevices << std::endl;
    }

    if (timeLeft > 0) {
        timeLeft--;
    }
}

void System::setupDevices() {
    coffee = std::make_unique<Coffee>(0);
    water = std::make_unique<Water>(0);
    milk = std::make_unique<Milk>(0);
    sugar = std::make_unique<Sugar>(0);
    vanillaSugar = std::make_unique<VanillaSugar>(0);
    cinnamon = std::make_unique<Cinnamon>(0);
    cup = std::make_unique<Cup>();


    beanContainer = std::make_unique<BeanContainer>(this);
    coffeeGrinder = std::make_unique<CoffeeGrinder>(this);
    coffeePresser = std::make_unique<CoffeePresser>(this);

    waterContainer = std::make_unique<WaterContainer>(this);
    waterHeater = std::make_unique<WaterHeater>(this);

    milkContainer = std::make_unique<MilkContainer>(this);
    milkHeater = std::make_unique<MilkHeater>(this);

    sugarContainer = std::make_unique<SugarContainer>(this);
    vanillaSugarContainer = std::make_unique<VanillaSugarContainer>(this);
    cinnamonContainer = std::make_unique<CinnamonContainer>(this);
    cupContainer = std::make_unique<CupContainer>(this);

    coffeeBrewer = std::make_unique<CoffeeBrewer>(this);

    // Подключаем сигналы
    connectDeviceSignals(beanContainer.get());
    connectDeviceSignals(coffeeGrinder.get());
    connectDeviceSignals(coffeePresser.get());
    connectDeviceSignals(waterContainer.get());
    connectDeviceSignals(waterHeater.get());
    connectDeviceSignals(milkContainer.get());
    connectDeviceSignals(milkHeater.get());
    connectDeviceSignals(sugarContainer.get());
    connectDeviceSignals(vanillaSugarContainer.get());
    connectDeviceSignals(cinnamonContainer.get());
    connectDeviceSignals(cupContainer.get());
    connectDeviceSignals(coffeeBrewer.get());
}

void System::connectDeviceSignals(MachinePart* device) {
    connect(device, &MachinePart::progressUpdated, this, &System::onDeviceProgress);
    connect(device, &MachinePart::workFinished, this, &System::onDeviceFinished);
    connect(device, &MachinePart::workStarted, this, &System::onDeviceStarted);
}

// Добавляем реализацию слота onDeviceStarted
void System::onDeviceStarted(const QString& deviceName) {
    emit deviceStarted(deviceName);
}

void System::onDeviceProgress(const QString& deviceName, int timeLeft, int totalTime) {
    if (timeLeft % 5 == 0) {
        std::cout << deviceName.toUtf8().constData() << " time left: " << timeLeft << "/" << totalTime << std::endl;
    }
    emit deviceProgress(deviceName, timeLeft, totalTime);
}

void System::onDeviceFinished(const QString& deviceName) {
    if (!m_deviceCompleted.value(deviceName, false)) {
        m_deviceCompleted[deviceName] = true;
        m_completedDevices++;
        std::cout << deviceName.toUtf8().constData() << " completed " << m_completedDevices << "/" << m_totalDevices << std::endl;

        emit deviceFinished(deviceName);

        checkProcessCompletion();
    }
}

void System::checkProcessCompletion() {
    if (m_completedDevices == m_totalDevices - 1 && m_processRunning) {
        std::cout << "\nStarting coffee brewer" << std::endl;
        executeBrewing();
    }
    else if (m_completedDevices == m_totalDevices && m_processRunning) {
        m_processRunning = false;
        if (m_debugTimer->isActive()) {
            m_debugTimer->stop();
        }

        std::cout << "PROCESS COMPLETED! Coffee is ready!" << std::endl;
        Cup* cupPtr = dynamic_cast<Cup*>(cup.get());
        if (cupPtr) {
            std::cout << "\nFinal cup contents: "
                     << "\nCoffee: " << cupPtr->getCoffee()->getPortions()
                     << "\nWater: " << cupPtr->getWater()->getPortions()
                     << "\nMilk: " << cupPtr->getMilk()->getPortions()
                     << "\nSugar: " << cupPtr->getSugar()->getPortions()
                     << "\nVanilla Sugar: " << cupPtr->getVanillaSugar()->getPortions()
                     << "\nCinnamon: " << cupPtr->getCinnamon()->getPortions()<< std::endl;;
        }
        std::cout << "Total time: " << timeTotal << " seconds " << std::endl;

        emit processCompleted();
    }
}

void System::startProcess() {
    std::cout << "Recipe: " << recipe->getName().toUtf8().constData() << std::endl;

    m_processRunning = true;
    m_completedDevices = 0;
    m_totalDevices = 0;
    m_activeDevices.clear();
    m_deviceCompleted.clear();

    int portions;

    if (recipe->getCoffee() > 0) {
        m_totalDevices += 3; // beanContainer + coffeeGrinder + coffeePresser
    }
    if (recipe->getMilk() > 0) {
        m_totalDevices += 2; // milkContainer + milkHeater
    }
    if (recipe->getWater() > 0) {
        m_totalDevices += 2; // waterContainer + waterHeater
    }
    if (recipe->getSugar() > 0) {
        m_totalDevices += 1; // sugarContainer
    }
    if (recipe->getVanillaSugar() > 0) {
        m_totalDevices += 1; // vanillaSugarContainer
    }
    if (recipe->getCinnamon() > 0) {
        m_totalDevices += 1; // cinnamonContainer
    }
    m_totalDevices += 1; // cupContainer

    m_totalDevices += 1; // coffeeBrewer


    std::cout << "Total preparation devices: " << m_totalDevices << std::endl;

    timeTotal = calculateTime();
    timeLeft = timeTotal;

    std::cout << "Estimated time: " << timeTotal << " s" << std::endl;

    executeCoffee();
    executeMilk();
    executeWater();
    executeSugar();
    executeVanillaSugar();
    executeCinnamon();
    executeCup();

}
void System::cancelProcess() {
    std::cout << "CANCELLING PROCESS" << std::endl;

    m_processRunning = false;
    if (m_debugTimer->isActive()) {
        m_debugTimer->stop();
    }

    for (MachinePart* device : std::as_const(m_activeDevices)) {
        if (device->isWorking()) {
            device->cancelWork();
        }
    }

    emit processCancelled();
}



void System::executeCoffee() {
    if (!m_processRunning) return;

    if (recipe->getCoffee() > 0) {
        m_activeDevices[beanContainer->getPartName()] = beanContainer.get();
        m_activeDevices[coffeeGrinder->getPartName()] = coffeeGrinder.get();
        m_activeDevices[coffeePresser->getPartName()] = coffeePresser.get();

        beanContainer->getIngredient(this->coffee, recipe->getCoffee());
        coffeeGrinder->convertIngredient(this->coffee);
        coffeePresser->convertIngredient(this->coffee);
    }
}

void System::executeMilk() {
    if (!m_processRunning) return;

    if (recipe->getMilk() > 0) {
        m_activeDevices[milkContainer->getPartName()] = milkContainer.get();
        m_activeDevices[milkHeater->getPartName()] = milkHeater.get();

        milkContainer->getIngredient(this->milk, recipe->getMilk());
        milkHeater->convertIngredient(this->milk);
    }
}

void System::executeWater() {
    if (!m_processRunning) return;

    if (recipe->getWater() > 0) {
        m_activeDevices[waterContainer->getPartName()] = waterContainer.get();
        m_activeDevices[waterHeater->getPartName()] = waterHeater.get();

        waterContainer->getIngredient(this->water, recipe->getWater());
        waterHeater->convertIngredient(this->water);
    }
}

void System::executeSugar() {
    if (!m_processRunning) return;

    if (recipe->getSugar() > 0) {
        m_activeDevices[sugarContainer->getPartName()] = sugarContainer.get();
        sugarContainer->getIngredient(this->sugar, recipe->getSugar());
    }
}

void System::executeVanillaSugar() {
    if (!m_processRunning) return;

    if (recipe->getVanillaSugar() > 0) {
        m_activeDevices[vanillaSugarContainer->getPartName()] = vanillaSugarContainer.get();
        vanillaSugarContainer->getIngredient(this->vanillaSugar, recipe->getVanillaSugar());
    }
}

void System::executeCinnamon() {
    if (!m_processRunning) return;

    if (recipe->getCinnamon() > 0) {
        m_activeDevices[cinnamonContainer->getPartName()] = cinnamonContainer.get();
        cinnamonContainer->getIngredient(this->cinnamon, recipe->getCinnamon());
    }
}

void System::executeCup() {
    if (!m_processRunning) return;

    m_activeDevices[cupContainer->getPartName()] = cupContainer.get();
    cupContainer->getIngredient(cup, 1);
}

void System::executeBrewing() {
    if (!m_processRunning) return;

    m_activeDevices[coffeeBrewer->getPartName()] = coffeeBrewer.get();

    coffeeBrewer->createCoffeeCup(
        std::move(coffee),
        std::move(water),
        std::move(milk),
        std::move(sugar),
        std::move(vanillaSugar),
        std::move(cinnamon),
        *cup);
}
int System::calculateTime(){
    int finalTime = 0;

    int coffeeTime = 0;
    if(recipe->getCoffee() > 0){
        coffeeTime += static_cast<int>(beanContainer->getPreparationTime() +
                                       coffeeGrinder->getPreparationTime() +
                                       coffeePresser->getPreparationTime());
    }

    int milkTime = 0;
    if(recipe->getMilk() > 0){
        milkTime += static_cast<int>(milkContainer->getPreparationTime() +
                                     milkHeater->getPreparationTime());
    }

    int waterTime = 0;
    if(recipe->getWater() > 0){
        waterTime += static_cast<int>(waterContainer->getPreparationTime() +
                                      waterHeater->getPreparationTime());
    }

    int sugarTime = 0;
    if(recipe->getSugar() > 0){
        sugarTime = static_cast<int>(sugarContainer->getPreparationTime());
    }

    int vanillaSugarTime = 0;
    if(recipe->getVanillaSugar() > 0){
        vanillaSugarTime = static_cast<int>(vanillaSugarContainer->getPreparationTime());
    }

    int cinnamonTime = 0;
    if(recipe->getCinnamon() > 0){
        cinnamonTime = static_cast<int>(cinnamonContainer->getPreparationTime());
    }

    int cupTime = static_cast<int>(cupContainer->getPreparationTime());

    int maxParallelTime = std::max({coffeeTime, milkTime, waterTime, sugarTime, vanillaSugarTime, cinnamonTime, cupTime});

    finalTime = maxParallelTime + static_cast<int>(coffeeBrewer->getPreparationTime());

    std::cout << "Time calculation: " << std::endl;
    std::cout << "  Coffee time: " << coffeeTime << " s"<< std::endl;;
    std::cout << "  Milk time: " << milkTime << " s"<< std::endl;;
    std::cout << "  Water time: " << waterTime << " s"<< std::endl;;
    std::cout << "  Sugar time: " << sugarTime << " s"<< std::endl;;
    std::cout << "  Vanilla Sugar time: " << vanillaSugarTime << " s"<< std::endl;;
    std::cout << "  Cinnamon time: " << cinnamonTime << " s"<< std::endl;;
    std::cout << "  Cup time: " << cupTime << " s"<< std::endl;;
    std::cout << "  Brewer time: " << coffeeBrewer->getPreparationTime() << " s"<< std::endl;;
    std::cout << "  Total time: " << finalTime << " s"<< std::endl;;

    return finalTime;
}
