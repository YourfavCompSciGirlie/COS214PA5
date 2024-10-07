#include "TurnOffAllLights.h"

/**
 * @file TurnOffAllLights.cpp
 * @brief Constructs a TurnOffAllLights command.
 * @param lights Pointer to the SmartLightingSystem that manages the lights.
 */
TurnOffAllLights::TurnOffAllLights(SmartLightingSystem *lights) : lights(lights) {}

/**
 * @brief Executes the command to turn off all lights.
 * This function turns off all lights in the SmartLightingSystem and
 * prints status messages to the console.
 */
void TurnOffAllLights::execute()
{
    std::cout << "Executing command: Turn off all lights..." << std::endl;
    lights->turnOff();
    std::cout << "Lights have been successfully turned off." << std::endl;
}

void TurnOffAllLights::update(const std::string &sensorType, const std::string &sensorData)
{
    (void)sensorType; // Mark sensorType as unused
    (void)sensorData; // Mark sensorData as unused
    std::cout << "The 'update()' method is intended for Observer classes only, not Command classes.\n";
}

// Stubbed functions
void TurnOffAllLights::performAction(const std::string &action)
{
    std::cout << "TurnOffAllLights: Performing action: " << action << std::endl;
    // Stubbed: Logic for specific actions would go here
}

std::string TurnOffAllLights::getDeviceType() const
{
    return "N/A";
}

std::string TurnOffAllLights::getStatus() const
{
    return "All lights are currently off.";
}