#include "TemperatureSensor.h"

/**
 * @brief Adds a device to the list of observers.
 * 
 * This function registers a device (observer) to be notified of changes in temperature.
 * 
 * @param device Pointer to the device (observer) to be added.
 */
void TemperatureSensor::addDevice(Device* device) 
{
    devices.push_back(device);
}

/**
 * @brief Removes a device from the list of observers.
 * 
 * This function unregisters a device (observer) so it no longer receives updates.
 * 
 * @param device Pointer to the device (observer) to be removed.
 */
void TemperatureSensor::removeDevice(Device* device) 
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

/**
 * @brief Notifies all registered devices of a temperature change.
 * 
 * This function iterates over all devices (observers) and updates them with the new temperature state.
 */
void TemperatureSensor::notifyDevices() 
{
    for (Device* device : devices) {
        device->update("temperature", sensorState);
    }
}

/**
 * @brief Simulates the detection of high temperature.
 * 
 * This function changes the sensor state to "high" and notifies all registered devices.
 */
void TemperatureSensor::detectHighTemperature() 
{
    sensorState = "high";
    notifyDevices();
}

/**
 * @brief Simulates the detection of low temperature.
 * 
 * This function changes the sensor state to "low" and notifies all registered devices.
 */
void TemperatureSensor::detectLowTemperature() 
{
    sensorState = "low";
    notifyDevices();
}
