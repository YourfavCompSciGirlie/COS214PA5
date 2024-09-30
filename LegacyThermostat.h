// Class definition for Component 2 - Adapter (Adaptee)

#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

#include <iostream>

class LegacyThermostat {

    private:
        float temperature;  // Current temperature set on the legacy thermostat.

    public:

        LegacyThermostat();
        void setTemperature(float temp);
        float getTemperature() const;
};

#endif // LEGACYTHERMOSTAT_H
