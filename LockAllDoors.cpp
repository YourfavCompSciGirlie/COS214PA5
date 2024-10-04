#include "LockAllDoors.h"

/**
 * @brief Constructs a LockAllDoors command.
 * @param locks Pointer to the SmartDoorLockSystem that manages the locks.
 */
LockAllDoors::LockAllDoors(SmartDoorLockSystem* locks) : locks(locks) {}

/**
 * @brief Executes the command to lock all doors.
 * This function locks all doors in the SmartDoorLockSystem and prints 
 * status messages to the console.
 */
void LockAllDoors::execute() 
{
    std::cout << "Executing command: Lock all doors..." << std::endl;
    locks->lockAll(); 
    std::cout << "All doors are now locked." << std::endl;
}


void LockAllDoors::update(const std::string& sensorType, const std::string& sensorData)
{
        (void)sensorType;  // Mark sensorType as unused
        (void)sensorData;  // Mark sensorData as unused
        std::cout << "The 'update()' method is intended for Observer classes only, not Command classes.\n";
}

// Stubbed functions
void LockAllDoors::performAction(const std::string& action) {
    std::cout << "LockAllDoors: Performing action: " << action << std::endl;
    // Stubbed: Logic for specific actions would go here
}

std::string LockAllDoors::getDeviceType() const {
    return "N/A";
}

std::string LockAllDoors::getStatus() const {
    return "All doors are currently locked.";
}