// Class definition for Component 4 - Observer (ConcreteObserver)

#include "Dehumidifier.h"
#include <iostream>

/**
 * @file Dehumidifier.cpp
 * @brief Responds to a sensor notification.
 *
 * This function is triggered when a sensor detects a change in humidity levels.
 * Based on the sensor data, the dehumidifier either activates or deactivates.
 *
 * @param sensorType The type of sensor (e.g., "humidity").
 * @param sensorData The data received from the sensor (e.g., "high", "low").
 */
void Dehumidifier::update(const std::string &sensorType, const std::string &sensorData)
{
    if (sensorType == "humidity" && sensorData == "high")
    {
        std::cout << "Dehumidifier: High humidity detected! Activating dehumidifier.\n";
    }
    else if (sensorType == "humidity" && sensorData == "low")
    {
        std::cout << "Dehumidifier: Humidity at normal level. Deactivating dehumidifier.\n";
    }
}

/**
 * @brief Executes the dehumidifier's core functionality.
 *
 * This function handles the dehumidifier's actions based on the latest sensor data,
 * such as activating or deactivating the device in response to humidity levels.
 */
void Dehumidifier::execute()
{
    std::cout << "Dehumidifier: Executing humidity control based on sensor notification.\n";
}

/**
 * @brief Perform a specified action on the dehumidifier (e.g., Adjust humidity).
 *
 * This method takes a string action and performs the respective operation on the dehumidifier system.
 * The action could be "Activate", "Deactivate", or any other valid operation.
 *
 * @param action The action to be performed on the dehumidifier.
 */
void Dehumidifier::performAction(const std::string &action)
{
    std::cout << "Dehumidifier: Performing action -> " << action << std::endl;
    // Stub implementation: Replace this with actual logic to adjust humidity levels.
}

/**
 * @brief Retrieves the current status of the dehumidifier.
 *
 * This function returns the current operational state of the dehumidifier, such as "On" or "Off".
 *
 * @return A string representing the current status of the dehumidifier.
 */
std::string Dehumidifier::getStatus() const
{
    std::cout << "Dehumidifier: Getting current status..." << std::endl;
    // Stub implementation: Return the actual status of the dehumidifier.
    return "Dehumidifier is Off"; // Example status
}

/**
 * @brief Retrieves the type of the device.
 *
 * This function returns the device type as a string, in this case, "Dehumidifier".
 * It identifies the kind of device being managed.
 *
 * @return A string representing the type of the device (e.g., "Dehumidifier").
 */
std::string Dehumidifier::getDeviceType() const
{
    std::cout << "Dehumidifier: Getting device type..." << std::endl;
    return "Dehumidifier"; // Return the type of this device
}
