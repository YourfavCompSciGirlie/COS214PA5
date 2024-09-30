// Class definition for Component 2 - Adapter (Adaptee)

/**
 * @file LegacyThermostat.h
 * @brief Definition of the LegacyThermostat class.
 * 
 * This class represents a legacy thermostat device, allowing the management
 * of temperature settings. It provides methods to set and get the current
 * temperature of the legacy thermostat.
 */

#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

#include <iostream>

/**
 * @class LegacyThermostat
 * @brief Represents a legacy thermostat device.
 * 
 * The LegacyThermostat class manages the temperature setting for a legacy
 * thermostat. It contains methods for setting and retrieving the temperature.
 */

class LegacyThermostat {

    private:
        float temperature;  ///< Current temperature set on the legacy thermostat.

    public:

        /**
         * @brief Constructor that initializes the legacy thermostat with a default temperature.
         * 
         * The default temperature is set to 22.0 degrees Celsius.
         */
        LegacyThermostat();

        /**
         * @brief Sets the temperature on the legacy thermostat.
         * 
         * This method updates the temperature value of the legacy thermostat
         * and prints the new temperature to the console.
         * 
         * @param temp The temperature to set (in degrees Celsius).
         */
        void setLegacyTemperature(float temp);

        /**
         * @brief Gets the current temperature from the legacy thermostat.
         * 
         * This method retrieves the current temperature setting of the
         * legacy thermostat.
         * 
         * @return The current temperature (in degrees Celsius).
         */
        float getLegacyTemperature() const;
};

#endif // LEGACYTHERMOSTAT_H
