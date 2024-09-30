// Class implementation for Component 2 - Adapter (Adaptee)

#include "LegacyThermostat.h"

LegacyThermostat::LegacyThermostat() : temperature(22.0f) {
    // Constructor sets a default temperature
}

void LegacyThermostat::setTemperature(float temp) {
    temperature = temp;
    std::cout << "Legacy Thermostat: Temperature set to " << temperature << "°C\n";
}

float LegacyThermostat::getTemperature() const {
    return temperature;
}
