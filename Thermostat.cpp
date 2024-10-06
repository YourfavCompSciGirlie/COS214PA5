#include "Thermostat.h"
#include <iostream>

// Implementation of Thermostat

/**
 * @brief Updates the thermostat based on the sensor's notification.
 * 
 * This function adjusts the thermostat settings based on the sensor type and data received.
 * 
 * @param sensorType Type of the sensor that triggered the update.
 * @param sensorData Data indicating the sensor's state (e.g., "high", "low").
 */
void Thermostat::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "temperature" && sensorData == "high") {
        std::cout << "Thermostat: High temperature detected! Adjusting to cooler settings.\n";
    } else if (sensorType == "temperature" && sensorData == "low") {
        std::cout << "Thermostat: Low temperature detected! Adjusting to warmer settings.\n";
    }
}

/**
 * @brief Executes the thermostat's actions based on notifications received from sensors.
 * 
 * This function will be called to perform any necessary adjustments based on the sensor's input.
 */
void Thermostat::execute() 
{
    std::cout << "Thermostat: Executing temperature adjustment based on sensor notification.\n";
}

/**
 * @brief Perform an action on the thermostat (e.g., Adjust temperature).
 * 
 * @param action The action to be performed on the thermostat.
 */
void Thermostat::performAction(const std::string& action) {
    std::cout << "Thermostat: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual logic to adjust the temperature.
}

/**
 * @brief Get the current status of the thermostat (e.g., Current temperature).
 * 
 * @return A string representing the current status of the thermostat.
 */
std::string Thermostat::getStatus() const {
    std::cout << "Thermostat: Getting current status..." << std::endl;
    // Stub implementation: Return the actual current temperature.
    return "22°C";  
}

/**
 * @brief Get the device type (e.g., "Thermostat").
 * 
 * @return A string representing the type of the device.
 */
std::string Thermostat::getDeviceType() const {
    std::cout << "Thermostat: Getting device type..." << std::endl;
    return "Thermostat";  // Return the type of this device
}
