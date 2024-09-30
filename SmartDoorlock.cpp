// Class implementation for Component 1 - Composite (Leaf)

/**
 * @file SmartDoorlock.cpp
 * @brief Implementation of the SmartDoorlock class.
 * 
 * This file contains the implementation of the methods defined in SmartDoorlock.h,
 * providing the behavior for a smart door lock device. The SmartDoorlock class uses 
 * the state pattern to handle locking and unlocking actions.
 */

#include "SmartDoorlock.h"
#include "LockedState.h"
#include "UnlockedState.h"


/**
 * @brief Construct a new SmartDoorlock object.
 * 
 * Initializes a new SmartDoorlock device and sets its initial state to "unlocked" 
 * by associating it with the UnlockedState object. The device can transition between 
 * locked and unlocked states using the performAction method.
 */
SmartDoorlock::SmartDoorlock() : SmartDevice("SmartDoorlock") {
    // Initialize the DoorLock with an UnlockedState
    this->setState(std::make_shared<UnlockedState>());
}


/**
 * @brief Perform an action on the smart door lock.
 * 
 * This method delegates the provided action to the current state of the smart door lock.
 * Depending on the action, the state may toggle between locked and unlocked.
 * 
 * @param action The action to be performed, such as "Lock" or "Unlock".
 */
void SmartDoorlock::performAction(const std::string& action) {
    // Delegate action to the current state
    state->performAction(shared_from_this(), action);
}


/**
 * @brief Get the current status of the smart door lock.
 * 
 * This method retrieves and returns the current status of the smart door lock,
 * which is determined by the device's current state. The possible statuses
 * include "locked" or "unlocked".
 * 
 * @return std::string The current status of the smart door lock.
 */
std::string SmartDoorlock::getStatus() const {
    return state->getStatus(); // Return the current state status
}



/**
 * @brief Get the device type of the smart door lock.
 * 
 * This method returns a string indicating the type of device, which is "SmartDoorLock".
 * 
 * @return std::string The string "SmartDoorLock".
 */
std::string SmartDoorlock::getDeviceType() const {
    return "SmartDoorLock";
}
