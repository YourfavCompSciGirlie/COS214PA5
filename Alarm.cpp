#include "Alarm.h"


/**
 * @brief Responds to a sensor notification.
 * 
 * This function simulates an alarm triggering in response to movement detected by a sensor. 
 * It prints creative messages based on the type of alert triggered (e.g., mild warning or full alarm).
 */
void Alarm::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "motion" && sensorData == "detected") {
        std::cout << "SmartAlarm: Motion detected! Sounding alarm.\n";
    } else if (sensorType == "motion" && sensorData == "clear") {
        std::cout << "SmartAlarm: Motion clear. Alarm deactivated.\n";
    }
}


void Alarm::execute() {
    std::cout << "SmartAlarm: Executing alarm activation/deactivation based on sensor notification.\n";
}

/**
 * @brief Perform an action on the alarm (e.g., Activate or Deactivate).
 * 
 * @param action The action to be performed on the alarm.
 */
void Alarm::performAction(const std::string& action) {
    std::cout << "Alarm: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual action logic (e.g., activating the alarm).
}

/**
 * @brief Get the current status of the alarm (e.g., Activated or Deactivated).
 * 
 * @return A string representing the current status of the alarm.
 */
std::string Alarm::getStatus() const {
    std::cout << "Alarm: Getting current status..." << std::endl;
    // Stub implementation: Return the actual status of the alarm.
    return "Deactivated";  // Example status
}

/**
 * @brief Get the device type (e.g., "Alarm").
 * 
 * @return A string representing the type of the device.
 */
std::string Alarm::getDeviceType() const {
    std::cout << "Alarm: Getting device type..." << std::endl;
    return "Alarm";  // Return the type of this device
}