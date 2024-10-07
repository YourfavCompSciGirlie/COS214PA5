#include "Lights.h"


/**
 * @file Lights.cpp
 * @brief Responds to a sensor notification.
 * 
 * This function simulates the light turning on in response to movement detected by a sensor. 
 * It could also print different levels of brightness depending on the time of day.
 */
void Lights::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "motion" && sensorData == "detected") {
        std::cout << "SmartLight: Motion detected! Turning on light and adjusting brightness.\n";
    } else if (sensorType == "motion" && sensorData == "clear") {
        std::cout << "SmartLight: No motion detected. Dimming lights.\n";
    }
}


void Lights::execute() 
{
    std::cout << "SmartLight: Executing light adjustment based on sensor notification.\n";
}

/**
 * @brief Perform an action on the lights (e.g., Turn On or Turn Off).
 * 
 * @param action The action to be performed on the lights.
 */
void Lights::performAction(const std::string& action) {
    std::cout << "Lights: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual logic to turn the lights on/off.
}

/**
 * @brief Get the current status of the lights (e.g., On or Off).
 * 
 * @return A string representing the current status of the lights.
 */
std::string Lights::getStatus() const {
    std::cout << "Lights: Getting current status..." << std::endl;
    // Stub implementation: Return the actual status of the lights.
    return "Off";  // Example status
}

/**
 * @brief Get the device type (e.g., "Lights").
 * 
 * @return A string representing the type of the device.
 */
std::string Lights::getDeviceType() const {
    std::cout << "Lights: Getting device type..." << std::endl;
    return "Lights";  // Return the type of this device
}