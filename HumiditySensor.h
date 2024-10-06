// Class definition for Component 4 - Observer (ConcreteSubject)

#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"
#include <vector>
#include <string>

/**
 * @brief The HumiditySensor class, a concrete subject that detects and notifies devices about humidity changes.
 * 
 * This class inherits from the Sensor class and represents a humidity sensor. It maintains a list of 
 * registered devices (observers) and notifies them when humidity levels change, triggering specific actions.
 */
class HumiditySensor : public Sensor {
private:
    std::vector<Device*> devices;  ///< List of registered devices (observers).
    std::string sensorState = "normal";  ///< The current state of the humidity sensor (default: "normal").

public:
    /**
     * @brief Adds a device to the list of observers.
     * 
     * Registers a device to be notified when a change in humidity is detected.
     * 
     * @param device A pointer to the device that should be added to the observer list.
     */
    void addDevice(Device* device) override;

    /**
     * @brief Removes a device from the list of observers.
     * 
     * Unregisters a device so it will no longer receive notifications about humidity changes.
     * 
     * @param device A pointer to the device that should be removed from the observer list.
     */
    void removeDevice(Device* device) override;

    /**
     * @brief Notifies all registered devices of a change in humidity.
     * 
     * This function iterates through all the registered devices and updates them
     * with the current humidity state ("high" or "low").
     */
    void notifyDevices() override;

    /**
     * @brief Simulates detection of high humidity.
     * 
     * This method changes the sensor state to "high" and notifies all registered devices.
     */
    void detectHighHumidity();

    /**
     * @brief Simulates detection of low humidity.
     * 
     * This method changes the sensor state to "low" and notifies all registered devices.
     */
    void detectLowHumidity();
};

#endif 
