//Class defintion for Component 4  - Observer(ConcreteObserver)

#include "Dehumidifier.h"
#include <iostream>


void Dehumidifier::update(const std::string& sensorType, const std::string& sensorData) 
{
    if (sensorType == "humidity" && sensorData == "high") {
        std::cout << "Dehumidifier: High humidity detected! Activating dehumidifier.\n";
    } else if (sensorType == "humidity" && sensorData == "low") {
        std::cout << "Dehumidifier: Humidity at normal level. Deactivating dehumidifier.\n";
    }
    
}


void Dehumidifier::execute() {
    std::cout << "Dehumidifier: Executing humidity control based on sensor notification.\n";
}

/**
 * @brief Perform an action on the dehumidifier (e.g., Adjust humidity).
 * 
 * @param action The action to be performed on the dehumidifier.
 */
void Dehumidifier::performAction(const std::string& action) {
    std::cout << "Dehumidifier: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual logic to adjust humidity levels.
}

/**
 * @brief Get the current status of the dehumidifier (e.g., On/Off status).
 * 
 * @return A string representing the current status of the dehumidifier.
 */
std::string Dehumidifier::getStatus() const {
    std::cout << "Dehumidifier: Getting current status..." << std::endl;
    // Stub implementation: Return the actual status of the dehumidifier.
    return "Dehumidifier is Off";  // Example status
}

/**
 * @brief Get the device type (e.g., "Dehumidifier").
 * 
 * @return A string representing the type of the device.
 */
std::string Dehumidifier::getDeviceType() const {
    std::cout << "Dehumidifier: Getting device type..." << std::endl;
    return "Dehumidifier";  // Return the type of this device
}