#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <algorithm>
#include "Device.h"

/**
 * @brief Abstract Subject class in the Observer pattern.
 * 
 * The Sensor class acts as a base class for concrete sensor types (e.g., motion sensor, humidity sensor).
 * It maintains a list of devices (observers) that are interested in receiving updates when the sensor state changes.
 */
class Sensor 
{
public:
    /**
     * @brief Registers a device to receive notifications when the sensor state changes.
     * 
     * This method should be overridden in derived classes to add a device to the list of observers.
     * 
     * @param device Pointer to the device (observer) to be added.
     */
    virtual void addDevice(Device* device) = 0;

    /**
     * @brief Unregisters a device from receiving notifications.
     * 
     * This method should be overridden in derived classes to remove a device from the list of observers.
     * 
     * @param device Pointer to the device (observer) to be removed.
     */
    virtual void removeDevice(Device* device) = 0;

    /**
     * @brief Notifies all registered devices of a change in the sensor state.
     * 
     * This method should be overridden in derived classes to notify each observer about the change in sensor state.
     */
    virtual void notifyDevices() = 0;

    /**
     * @brief Virtual destructor for Sensor.
     * 
     * Ensures proper cleanup when a derived class object is deleted.
     */
    virtual ~Sensor() {}
};

#endif // SENSOR_H
