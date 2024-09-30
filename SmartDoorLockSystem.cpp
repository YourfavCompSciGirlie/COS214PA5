#include "SmartDoorLockSystem.h"
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::seconds

/**
 * @brief Locks all doors in the smart door lock system.
 * Simulates the locking process with status messages and delays 
 * to represent the operation.
 */
void SmartDoorLockSystem::lockAll() {
    std::cout << "Initiating locking procedure for all doors..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Step 1] Sending lock signals to all smart door locks..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate processing time
    std::cout << "[Step 2] Verifying lock statuses for each door..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Step 3] Finalizing lock procedure..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate processing time
    std::cout << "[Success] All doors are securely locked!" << std::endl;

    std::cout << "Security status: Doors locked and secured at " 
              << __TIME__ << " on " << __DATE__ << "." << std::endl;
}
