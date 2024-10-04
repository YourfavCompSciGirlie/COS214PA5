#include "Thermostat.h"
#include <iostream>

// Implementation of Thermostat
void Thermostat::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "temperature" && sensorData == "high") {
        std::cout << "Thermostat: High temperature detected! Adjusting to cooler settings.\n";
    } else if (sensorType == "temperature" && sensorData == "low") {
        std::cout << "Thermostat: Low temperature detected! Adjusting to warmer settings.\n";
    }
}


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
    return "22°C";  // Example status
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