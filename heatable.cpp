#include "heatable.h"

void Heatable::setTemperature(double temperature){
    this->temperature = temperature;
};
double Heatable::getTemperature() const{
    return this->temperature;
};
void Heatable::setRequiredTemperature(double requiredTemperature) {
    this->requiredTemperature = requiredTemperature;
};
double Heatable::getRequiredTemperature() const{
    return this->requiredTemperature;
};
