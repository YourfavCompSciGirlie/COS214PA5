// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file UnlockedState.cpp
 * @brief Implementation of the UnlockedState class methods.
 * 
 * This file provides the implementation of the UnlockedState class, specifically
 * defining the behavior when a device is in the "unlocked" state and handling the
 * transition to the "locked" state when needed.
 */

#include "UnlockedState.h"
#include "SmartDevice.h"
#include "LockedState.h"


/**
 * @brief Handles the action when the device is in the "Unlocked" state.
 * 
 * If the action is "Lock", the device's state changes to LockedState.
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "Lock").
 */
void UnlockedState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Lock") {
        device->setState(std::make_shared<LockedState>());
    }
}


/**
 * @brief Returns the status of the device in the "Unlocked" state.
 * 
 * @return A string "unlocked" representing the current status of the device.
 */
std::string UnlockedState::getStatus() const {
    return "unlocked";
}
