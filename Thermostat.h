/**
 * @file Thermostat.h
 * @brief Defines the Thermostat class, a concrete observer and device, 
 *        inheriting from the base Device class. This class is responsible for 
 *        performing thermostat-related actions and responding to sensor updates.
 */

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

/**
 * @class Thermostat
 * @brief Concrete Observer and Device class representing a thermostat in the system.
 * 
 * The Thermostat class inherits from Device and implements methods for performing actions,
 * getting status updates, and responding to sensor notifications.
 */
class Thermostat : public Device {
public:
    /**
     * @brief Executes the primary function of the thermostat (e.g., adjust temperature).
     */
    void execute() override;

    /**
     * @brief Updates the thermostat based on sensor data.
     * 
     * @param sensorType The type of sensor triggering the update (e.g., "Temperature").
     * @param sensorData The data received from the sensor (e.g., "25°C").
     */
    void update(const std::string& sensorType, const std::string& sensorData) override;

    /**
     * @brief Perform an action on the thermostat (e.g., Adjust Temperature).
     * 
     * @param action The action to be performed on the thermostat.
     */
    void performAction(const std::string& action) override;

    /**
     * @brief Get the current status of the thermostat (e.g., Current Temperature).
     * 
     * @return A string representing the current status of the thermostat.
     */
    std::string getStatus() const override;

    /**
     * @brief Get the device type (e.g., "Thermostat").
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() const override;
};

#endif // THERMOSTAT_H
