#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

// Concrete Observer (Thermostat)
class Thermostat : public Device {
public:
    void execute() override;
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

#endif 
