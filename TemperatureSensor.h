// Class definition for Component 4 - Observer (ConcreteSubject)

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"

/**
 * @brief The TemperatureSensor class is a concrete subject in the Observer pattern.
 * 
 * This class is responsible for monitoring temperature changes and notifying
 * registered devices (observers) about these changes.
 */
class TemperatureSensor : public Sensor {
private:
    std::vector<Device*> devices; ///< List of registered devices (observers).
    std::string sensorState = "normal"; ///< Initial temperature state.

public:
    /**
     * @brief Adds a device to the list of observers.
     * 
     * This function registers a device (observer) to be notified of temperature changes.
     * 
     * @param device Pointer to the device (observer) to be added.
     */
    void addDevice(Device* device) override;

    /**
     * @brief Removes a device from the list of observers.
     * 
     * This function unregisters a device (observer) so it no longer receives updates.
     * 
     * @param device Pointer to the device (observer) to be removed.
     */
    void removeDevice(Device* device) override;

    /**
     * @brief Notifies all registered devices of a temperature change.
     * 
     * This function iterates over all devices (observers) and updates them with the new temperature state.
     */
    void notifyDevices() override;

    /**
     * @brief Simulates the detection of high temperature.
     * 
     * This function changes the sensor state to "high" and notifies all registered devices.
     */
    void detectHighTemperature();

    /**
     * @brief Simulates the detection of low temperature.
     * 
     * This function changes the sensor state to "low" and notifies all registered devices.
     */
    void detectLowTemperature();
};

#endif // TEMPERATURESENSOR_H
