#include "Alarm.h"


/**
 * @brief Responds to a sensor notification.
 * 
 * This function is triggered when a sensor detects a change in its state.
 * Depending on the type of alert and data received, it will simulate an alarm being triggered or cleared.
 * 
 * @param sensorType The type of sensor (e.g., "motion").
 * @param sensorData The data received from the sensor (e.g., "detected", "clear").
 */
void Alarm::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "motion" && sensorData == "detected") {
        std::cout << "SmartAlarm: Motion detected! Sounding alarm.\n";
    } else if (sensorType == "motion" && sensorData == "clear") {
        std::cout << "SmartAlarm: Motion clear. Alarm deactivated.\n";
    }
}

/**
 * @brief Executes the alarm's core functionality.
 * 
 * This function initiates the alarm's activation or deactivation based on the most recent sensor notifications.
 */
void Alarm::execute() {
    std::cout << "SmartAlarm: Executing alarm activation/deactivation based on sensor notification.\n";
}

/**
 * @brief Perform a specified action on the alarm (e.g., Activate or Deactivate).
 * 
 * This method takes a string action and performs the respective operation on the alarm system.
 * The action could be "Activate", "Deactivate", or any other valid operation.
 * 
 * @param action The action to be performed on the alarm.
 */
void Alarm::performAction(const std::string& action) {
    std::cout << "Alarm: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual action logic (e.g., activating the alarm).
}

/**
 * @brief Retrieves the current status of the alarm.
 * 
 * This function provides the current state of the alarm, such as "Activated" or "Deactivated".
 * 
 * @return A string representing the current status of the alarm.
 */
std::string Alarm::getStatus() const {
    std::cout << "Alarm: Getting current status..." << std::endl;
    // Stub implementation: Return the actual status of the alarm.
    return "Deactivated";  // Example status
}

/**
 * @brief Retrieves the type of the device.
 * 
 * This function returns the device type as a string, in this case, "Alarm".
 * It identifies the kind of device being managed.
 * 
 * @return A string representing the type of the device (e.g., "Alarm").
 */
std::string Alarm::getDeviceType() const {
    std::cout << "Alarm: Getting device type..." << std::endl;
    return "Alarm";  // Return the type of this device
}
