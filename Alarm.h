#include "Device.h"
#include <iostream>

/**
 * @file Alarm.h
 * @brief Concrete Alarm class that responds to sensor notifications by triggering an alarm.
 */
class Alarm : public Device
{
public:
    // For Observer  pattern
    void execute() override;
    void update(const std::string &sensorType, const std::string &sensorData);

    /**
     * @brief Stub method to perform an action on the alarm.
     *
     * @param action The action to be performed (e.g., "Activate", "Deactivate").
     */
    void performAction(const std::string &action) override;

    /**
     * @brief Stub method to get the current status of the alarm.
     *
     * @return A string representing the status (e.g., "Activated", "Deactivated").
     */
    std::string getStatus() const override;

    /**
     * @brief Stub method to get the device type.
     *
     * @return A string representing the type of the device (e.g., "Alarm").
     */
    std::string getDeviceType() const override;
};
