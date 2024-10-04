//Class defintion for Component 4  - Observer(ConcreteObserver)

#ifndef DEHUMIDIFIER_H
#define DEHUMIDIFIER_H

#include "Device.h"

class Dehumidifier : public Device 
{
public:
    void update(const std::string& sensorType, const std::string& sensorData) override;
    void execute() override;

    /**
     * @brief Perform an action on the dehumidifier (e.g., Adjust humidity).
     * 
     * @param action The action to be performed on the dehumidifier.
     */
    void performAction(const std::string& action) override;

    /**
     * @brief Get the current status of the dehumidifier (e.g., On/Off status).
     * 
     * @return A string representing the current status of the dehumidifier.
     */
    std::string getStatus() const override;

    /**
     * @brief Get the device type (e.g., "Dehumidifier").
     * 
     * @return A string representing the device type.
     */
    std::string getDeviceType() const override;
};
#endif 
