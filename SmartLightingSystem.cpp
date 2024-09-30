#include "SmartLightingSystem.h"
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::seconds

/**
 * @brief Turns off all lights in the smart lighting system.
 * Simulates the process of turning off the lights with status messages 
 * and delays to represent the operation.
 */
void SmartLightingSystem::turnOff() {
    std::cout << "Initiating lighting system shutdown..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Step 1] Dimming lights for gradual power-down..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate processing time
    std::cout << "[Step 2] Shutting off non-essential lighting..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Step 3] Verifying that all lights are off..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Success] All lights are now off." << std::endl;

    std::cout << "Energy conservation: All lights turned off at " 
              << __TIME__ << " on " << __DATE__ << "." << std::endl;
}
