// Class implementation for Component 2 - Adapter (Adaptee)

/**
 * @file LegacyThermostat.cpp
 * @brief Implementation of the LegacyThermostat class methods.
 * 
 * This file provides the implementation of the LegacyThermostat class,
 * defining the behavior for setting and retrieving the temperature of a
 * legacy thermostat.
 */

#include "LegacyThermostat.h"


/**
 * @brief Constructor that initializes the legacy thermostat with a default temperature.
 * 
 * The default temperature is set to 22.0 degrees Celsius.
 */
LegacyThermostat::LegacyThermostat() : temperature(22.0f) {
    // Constructor sets a default temperature
}


/**
 * @brief Sets the temperature on the legacy thermostat.
 * 
 * This method updates the temperature value of the legacy thermostat
 * and prints the new temperature to the console.
 * 
 * @param temp The temperature to set (in degrees Celsius).
 */
void LegacyThermostat::setLegacyTemperature(float temp) {
    temperature = temp;
    std::cout << "Legacy Thermostat: Temperature set to " << temperature << "°C\n";
}



/**
 * @brief Gets the current temperature from the legacy thermostat.
 * 
 * This method retrieves the current temperature setting of the
 * legacy thermostat.
 * 
 * @return The current temperature (in degrees Celsius).
 */
float LegacyThermostat::getLegacyTemperature() const {
    return temperature;
}
