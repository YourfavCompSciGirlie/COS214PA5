// Class implementation for SmartThermostatIntegrator (Adapter)

/**
 * @file SmartThermostatIntegrator.cpp
 * @brief Implementation of the SmartThermostatIntegrator class methods.
 * 
 * This file provides the implementation of the SmartThermostatIntegrator class,
 * which adapts a legacy thermostat's interface for use in the smart home system.
 */

#include "SmartThermostatIntegrator.h"


/**
 * @brief Constructor that initializes the SmartThermostatIntegrator with a legacy thermostat.
 * 
 * @param legacyThermostat Shared pointer to the legacy thermostat.
 */
SmartThermostatIntegrator::SmartThermostatIntegrator(std::shared_ptr<LegacyThermostat> legacyThermostat)
    : legacyThermostat(legacyThermostat) {}


/**
 * @brief Sets the temperature on the integrated legacy thermostat.
 * 
 * This method delegates the temperature setting to the legacy thermostat.
 * 
 * @param temp The temperature to set (in degrees Celsius).
 */
void SmartThermostatIntegrator::setTemperature(float temp) {
    legacyThermostat->setLegacyTemperature(temp); // Delegate the setting of temperature to the legacy thermostat
}


/**
 * @brief Gets the current temperature reading from the integrated legacy thermostat.
 * 
 * This method retrieves the current temperature from the legacy thermostat.
 * 
 * @return The current temperature (in degrees Celsius).
 */
float SmartThermostatIntegrator::getTemperature() const {
    return legacyThermostat->getLegacyTemperature(); // Delegate the getting of temperature to the legacy thermostat
}


/**
 * @brief Performs an action on the device.
 * 
 * This method handles actions such as increasing or decreasing
 * the temperature of the legacy thermostat based on the provided action.
 * 
 * @param action The action to perform, such as "IncreaseTemperature" or "DecreaseTemperature".
 */
void SmartThermostatIntegrator::performAction(const std::string& action) {
    if (action == "IncreaseTemperature") {
        float currentTemp = getTemperature();
        setTemperature(currentTemp + 1.0f); // Increase by 1 degree
    } else if (action == "DecreaseTemperature") {
        float currentTemp = getTemperature();
        setTemperature(currentTemp - 1.0f); // Decrease by 1 degree
    }
}


/**
 * @brief Gets the status of the SmartThermostatIntegrator.
 * 
 * This method returns a string representing the current status of the
 * SmartThermostatIntegrator, including the current temperature.
 * 
 * @return A string representing the current status.
 */
std::string SmartThermostatIntegrator::getStatus() const {
    std::ostringstream statusStream;
    statusStream << std::fixed << std::setprecision(1); // Set fixed format and 1 decimal precision
    statusStream << "SmartThermostatIntegrator: Current temperature is " 
                 << getTemperature() << "°C"; // Format the temperature directly in the stream
    return statusStream.str(); // Return the formatted string
}


/**
 * @brief Gets the type of the device.
 * 
 * This method returns the type of the device as a string.
 * 
 * @return A string representing the device type.
 */
std::string SmartThermostatIntegrator::getDeviceType() const {
    return "SmartThermostatIntegrator";
}

// Stubs for the execute and update methods
void SmartThermostatIntegrator::execute() {
    // Stub: To be implemented in future iterations
}


/**
 * @brief Updates the smart device in response to sensor notifications (Observer pattern).
 * 
 * This method will be implemented to handle sensor updates.
 * 
 * @param sensorType The type of the sensor (e.g., "TemperatureSensor").
 * @param sensorData The data received from the sensor.
 */
void SmartThermostatIntegrator::update(const std::string& sensorType, const std::string& sensorData) {
    (void)sensorType;  // Mark sensorType as unused
    (void)sensorData;  // Mark sensorData as unused
    // Stub: To be implemented in future iterations
}