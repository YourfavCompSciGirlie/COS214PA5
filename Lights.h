#include "Device.h"
#include <iostream>

/**
 * @brief Concrete Light class that responds to sensor notifications by turning on/off.
 */
class Lights : public Device 
{
public:
   
   //this is for Obsever  pattern
   Lights(){};
   void execute() override;
    void update(const std::string& sensorType, const std::string& sensorData)override;

    /**
     * @brief Stub method to perform an action on the lights (e.g., Turn On, Turn Off).
     * 
     * @param action The action to be performed on the lights.
     */
    void performAction(const std::string& action) override;

    /**
     * @brief Stub method to get the current status of the lights.
     * 
     * @return A string representing the status (e.g., "On", "Off").
     */
    std::string getStatus() const override;

    /**
     * @brief Stub method to get the device type.
     * 
     * @return A string representing the device type (e.g., "Lights").
     */
    std::string getDeviceType() const override;
};
