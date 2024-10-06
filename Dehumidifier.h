// Class definition for Component 4 - Observer (ConcreteObserver)

#ifndef DEHUMIDIFIER_H
#define DEHUMIDIFIER_H

#include "Device.h"

/**
 * @brief The Dehumidifier class, a concrete observer that reacts to changes in sensor data.
 * 
 * This class inherits from the Device class and represents a dehumidifier. It responds
 * to changes in humidity levels and takes actions accordingly, such as activating or 
 * deactivating the dehumidifier.
 */
class Dehumidifier : public Device 
{
public:
    /**
     * @brief Respond to a sensor notification.
     * 
     * This function is called when the dehumidifier receives an update from the sensor.
     * It checks the type of sensor and the associated data to either activate or 
     * deactivate the dehumidifier based on humidity levels.
     * 
     * @param sensorType The type of sensor (e.g., "humidity").
     * @param sensorData The data received from the sensor (e.g., "high", "low").
     */
    void update(const std::string& sensorType, const std::string& sensorData) override;

    /**
     * @brief Executes the dehumidifier's core functionality.
     * 
     * This method runs the dehumidifier's logic, managing its state based on the 
     * latest sensor notifications. It can trigger actions like activating or 
     * deactivating the device.
     */
    void execute() override;

    /**
     * @brief Perform an action on the dehumidifier (e.g., Adjust humidity).
     * 
     * This method allows external commands to control the dehumidifier, such as
     * "Activate" or "Deactivate". The actions may involve adjusting the humidity 
     * levels or other relevant operations.
     * 
     * @param action The action to be performed on the dehumidifier.
     */
    void performAction(const std::string& action) override;

    /**
     * @brief Get the current status of the dehumidifier (e.g., On/Off status).
     * 
     * This function returns the current operational state of the dehumidifier, 
     * such as whether it is turned on or off.
     * 
     * @return A string representing the current status of the dehumidifier.
     */
    std::string getStatus() const override;

    /**
     * @brief Get the device type (e.g., "Dehumidifier").
     * 
     * This method returns the type of the device as a string, identifying it as 
     * a "Dehumidifier".
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() const override;
};

#endif 
