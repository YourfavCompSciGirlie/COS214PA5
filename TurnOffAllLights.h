//Class defintion for Component 3  - Command(ConcreteCommand)

#ifndef TURNOFFALLLIGHTS_H
#define TURNOFFALLLIGHTS_H

#include "SmartLightingSystem.h"
#include "Device.h"

/**
 * @file  TurnOffAllLights.h
 * @brief Command to turn off all lights in a smart lighting system.
 */
class TurnOffAllLights : public Device 
{
public:
    /**
     * @brief Constructs a TurnOffAllLights command.
     * @param lights Pointer to the SmartLightingSystem that manages the lights.
    */
    TurnOffAllLights(SmartLightingSystem* lights);

    /**
     * @brief Executes the command to turn off all lights.
     * This function turns off all lights in the SmartLightingSystem.
     */
    void execute();


    void update(const std::string& sensorType, const std::string& sensorData);

    // New methods for stubbing
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;
    std::string getStatus() const override;

private:
    SmartLightingSystem* lights; ///< Pointer to the smart lighting system.
};

#endif 

