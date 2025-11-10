#ifndef HEATABLE_H
#define HEATABLE_H

class Heatable{
protected:
    double temperature;
    double requiredTemperature;
public:
    Heatable() = default;
    virtual ~Heatable() = default;
    void setTemperature(double temperature);
    double getTemperature() const;
    void setRequiredTemperature(double requiredTemperature) ;
    double getRequiredTemperature() const;
};


#endif // HEATABLE_H
