// Class implementation for SmartThermostatIntegrator (Adapter)

#include "SmartThermostatIntegrator.h"

SmartThermostatIntegrator::SmartThermostatIntegrator(std::shared_ptr<LegacyThermostat> legacyThermostat)
    : legacyThermostat(legacyThermostat) {}

void SmartThermostatIntegrator::setTemperature(float temp) {
    legacyThermostat->setTemperature(temp); // Delegate the setting of temperature to the legacy thermostat
}

float SmartThermostatIntegrator::getTemperature() const {
    return legacyThermostat->getTemperature(); // Delegate the getting of temperature to the legacy thermostat
}

void SmartThermostatIntegrator::performAction(const std::string& action) {
    if (action == "IncreaseTemperature") {
        float currentTemp = getTemperature();
        setTemperature(currentTemp + 1.0f); // Increase by 1 degree
    } else if (action == "DecreaseTemperature") {
        float currentTemp = getTemperature();
        setTemperature(currentTemp - 1.0f); // Decrease by 1 degree
    }
}

std::string SmartThermostatIntegrator::getStatus() const {
    std::ostringstream statusStream;
    statusStream << std::fixed << std::setprecision(1); // Set fixed format and 1 decimal precision
    statusStream << "SmartThermostatIntegrator: Current temperature is " 
                 << getTemperature() << "°C"; // Format the temperature directly in the stream
    return statusStream.str(); // Return the formatted string
}

std::string SmartThermostatIntegrator::getDeviceType() const {
    return "SmartThermostatIntegrator";
}
