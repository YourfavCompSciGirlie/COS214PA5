// Class definition for Component 4 - Observer (ConcreteSubject)
/**
 * @file HumiditySensor.h
 * @brief The HumiditySensor class, a concrete subjects that reacts to changes in sensor data.
 *
 * This class inherits from the Device class and represents a dehumidifier. It responds
 * to changes in humidity levels and takes actions accordingly, such as activating or
 * deactivating the dehumidifier.
 */

#include "HumiditySensor.h"

/**
 * @file HumiditySensor.cpp
 * @brief Adds a device to the list of observers.
 *
 * This method registers a device (observer) to the humidity sensor, allowing
 * the sensor to notify the device when a change in humidity is detected.
 *
 * @param device A pointer to the device that needs to be added.
 */
void HumiditySensor::addDevice(Device *device)
{
    devices.push_back(device);
}

/**
 * @brief Removes a device from the list of observers.
 *
 * This method unregisters a device (observer) from the humidity sensor,
 * so the device will no longer receive notifications of humidity changes.
 *
 * @param device A pointer to the device that needs to be removed.
 */
void HumiditySensor::removeDevice(Device *device)
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

/**
 * @brief Notifies all registered devices of a change in humidity.
 *
 * This method iterates through all the registered devices (observers) and
 * sends an update to each one, indicating the current state of humidity
 * (either high or low).
 */
void HumiditySensor::notifyDevices()
{
    for (Device *device : devices)
    {
        device->update("humidity", sensorState);
    }
}

/**
 * @brief Simulates detection of high humidity.
 *
 * This method sets the sensor's state to "high" and notifies all registered
 * devices that the humidity level is high.
 */
void HumiditySensor::detectHighHumidity()
{
    sensorState = "high";
    notifyDevices();
}

/**
 * @brief Simulates detection of low humidity.
 *
 * This method sets the sensor's state to "low" and notifies all registered
 * devices that the humidity level is low.
 */
void HumiditySensor::detectLowHumidity()
{
    sensorState = "low";
    notifyDevices();
}
