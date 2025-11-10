cmake_minimum_required(VERSION 3.16)

project(CoffeeMachine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)


qt_add_executable(appCoffeeMachine
    main.cpp
)

qt_add_qml_module(appCoffeeMachine
    URI CoffeeMachine
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES ingredient.h ingredient.cpp
        SOURCES machinepart.h machinepart.cpp
        SOURCES concreteingredients.h concreteingredients.cpp
        SOURCES
        SOURCES containable.h
        SOURCES
        SOURCES convertible.h
        SOURCES heatable.h
        SOURCES system.h system.cpp
        SOURCES recipe.h recipe.cpp
        SOURCES
        SOURCES heatable.h heatable.cpp
        SOURCES
        SOURCES
        SOURCES
        SOURCES coffeedrinks.h
        SOURCES
        SOURCES
        SOURCES workable.h
        SOURCES workable.h
        SOURCES beancontainer.h beancontainer.cpp
        SOURCES watercontainer.h watercontainer.cpp
        SOURCES milkcontainer.h milkcontainer.cpp
        SOURCES sugarcontainer.h sugarcontainer.cpp
        SOURCES vanillasugarcontainer.h vanillasugarcontainer.cpp
        SOURCES cinnamoncontainer.h cinnamoncontainer.cpp
        SOURCES cupcontainer.h cupcontainer.cpp
        SOURCES milkheater.h milkheater.cpp
        SOURCES waterheater.h waterheater.cpp
        SOURCES coffeegrinder.h coffeegrinder.cpp
        SOURCES coffeepresser.h coffeepresser.cpp
        SOURCES coffeebrewer.h coffeebrewer.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appCoffeeMachine PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appCoffeeMachine
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appCoffeeMachine
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appCoffeeMachine
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
