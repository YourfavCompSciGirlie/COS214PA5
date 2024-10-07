/**
 * @file LockAllDoors.h
 * @brief The LockAllDoors class, a concrete command.
 *
 * 
 */

#include "LockAllDoors.h"

/**
 * @file LockAllDoors.cpp
 * @brief Constructs a LockAllDoors command.
 *
 * This constructor initializes the LockAllDoors command with a reference to
 * the SmartDoorLockSystem, which manages the locking mechanism for all doors.
 *
 * @param locks Pointer to the SmartDoorLockSystem that manages the locks.
 */
LockAllDoors::LockAllDoors(SmartDoorLockSystem *locks) : locks(locks) {}

/**
 * @brief Executes the command to lock all doors.
 *
 * This function triggers the SmartDoorLockSystem to lock all connected doors and
 * prints status messages indicating that the command has been executed.
 */
void LockAllDoors::execute()
{
    std::cout << "Executing command: Lock all doors..." << std::endl;
    locks->lockAll();
    std::cout << "All doors are now locked." << std::endl;
}

/**
 * @brief This update function is not used by the LockAllDoors class.
 *
 * Since LockAllDoors is a command class and not an observer class, the update
 * method is stubbed out and prints a message indicating it is not applicable.
 *
 * @param sensorType The type of sensor that triggered the update.
 * @param sensorData The data sent by the sensor.
 */
void LockAllDoors::update(const std::string &sensorType, const std::string &sensorData)
{
    (void)sensorType; // Mark sensorType as unused
    (void)sensorData; // Mark sensorData as unused
    std::cout << "The 'update()' method is intended for Observer classes only, not Command classes.\n";
}

/**
 * @brief Stubbed function for performing specific actions on the system.
 *
 * This function would handle specific actions related to the LockAllDoors command,
 * but it is currently a stub with no implemented logic.
 *
 * @param action The action to be performed.
 */
void LockAllDoors::performAction(const std::string &action)
{
    std::cout << "LockAllDoors: Performing action: " << action << std::endl;
    // Stubbed: Logic for specific actions would go here
}

/**
 * @brief Returns the type of device, which is not applicable for this class.
 *
 * Since LockAllDoors is a command class, it returns "N/A" for the device type.
 *
 * @return A string representing the device type (always "N/A").
 */
std::string LockAllDoors::getDeviceType() const
{
    return "N/A";
}

/**
 * @brief Returns the current status of the LockAllDoors command.
 *
 * This function returns a message indicating that all doors are currently locked.
 *
 * @return A string representing the status of the command (always "All doors are currently locked.").
 */
std::string LockAllDoors::getStatus() const
{
    return "All doors are currently locked.";
}
