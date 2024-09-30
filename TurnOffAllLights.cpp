#include "TurnOffAllLights.h"

/**
 * @brief Constructs a TurnOffAllLights command.
 * @param lights Pointer to the SmartLightingSystem that manages the lights.
 */
TurnOffAllLights::TurnOffAllLights(SmartLightingSystem* lights) : lights(lights) {}

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

void TurnOffAllLights::update(const std::string& sensorType, const std::string& sensorData)
{
        std::cout << "The 'update()' method is intended for Observer classes only, not Command classes.\n";
}