#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "coffeedrinks.h"
#include "system.h"
#include <memory>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("CoffeeMachine", "Main");

    std::map<const CoffeeDrinks,  std::unique_ptr<Recipe>> recipeMap;

    recipeMap.emplace(CoffeeDrinks::AMERICANO, std::make_unique<Recipe>("AMERICANO", 50, 0, 150));
    recipeMap.emplace(CoffeeDrinks::CAPPUCCINO, std::make_unique<Recipe>("CAPPUCCINO", 50, 150));
    recipeMap.emplace(CoffeeDrinks::ESPRESSO, std::make_unique<Recipe>("ESPRESSO", 50, 0, 40));
    recipeMap.emplace(CoffeeDrinks::FLATWHITE, std::make_unique<Recipe>("FLATWHITE", 50, 140));
    recipeMap.emplace(CoffeeDrinks::LATTE, std::make_unique<Recipe>("LATTE", 50, 180));
    recipeMap.emplace(CoffeeDrinks::RAF, std::make_unique<Recipe>("RAF", 50, 120, 0, 0, 30));
    recipeMap.emplace(CoffeeDrinks::MOCHA, std::make_unique<Recipe>("MOCHA", 50, 140,0,30));
    recipeMap.emplace(CoffeeDrinks::MACCHIATO, std::make_unique<Recipe>("MACCHIATO", 50, 120, 0, 0, 30));

    int sugar = 0;
    int vanillaSugar = 0;
    int cinnamon = 0;

    //на основе определенных данных пользователя копируем
    std::unique_ptr<Recipe> mainRecipe = std::move(recipeMap[CoffeeDrinks::RAF]);

    std::unique_ptr<System> system = std::make_unique<System>(std::move(mainRecipe));
    system.get()->startProcess();

    return app.exec();
}
