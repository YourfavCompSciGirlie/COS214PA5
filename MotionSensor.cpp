#include "MotionSensor.h"

/**
 * @brief Registers a device to the motion sensor.
 * 
 * This function adds a device to the list of devices that will be notified 
 * when motion is detected or cleared.
 * 
 * @param device Pointer to the device to be added.
 */
void MotionSensor::addDevice(Device* device) 
{
    devices.push_back(device);
}

/**
 * @brief Removes a device from the motion sensor.
 * 
 * This function removes a device from the list of devices that are notified 
 * about motion changes.
 * 
 * @param device Pointer to the device to be removed.
 */
void MotionSensor::removeDevice(Device* device) 
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

/**
 * @brief Notifies all registered devices of motion state changes.
 * 
 * This function iterates over all devices registered to the motion sensor 
 * and calls their `update()` method, passing the current motion state.
 */
void MotionSensor::notifyDevices() 
{
    for (Device* device : devices) {
        device->update("motion", sensorState);
    }
}

/**
 * @brief Simulates motion detection by the sensor.
 * 
 * This function sets the sensor state to "detected" and notifies all registered 
 * devices that motion has been detected.
 */
void MotionSensor::detectMotion() 
{
    sensorState = "detected";
    notifyDevices();
}

/**
 * @brief Simulates clearing the motion detection.
 * 
 * This function sets the sensor state to "clear" and notifies all registered 
 * devices that motion is no longer detected.
 */
void MotionSensor::clearMotion() 
{
    sensorState = "clear";
    notifyDevices();
}
