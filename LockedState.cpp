// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file LockedState.cpp
 * @brief Implementation of the LockedState class methods.
 * 
 * This file provides the implementation of the LockedState class, specifically
 * defining the behavior when a device is in the "locked" state and handling the
 * transition to the "unlocked" state when needed.
 */

#include "LockedState.h"
#include "SmartDevice.h"
#include "UnlockedState.h"


/**
 * @brief Handles the action when the device is in the "Locked" state.
 * 
 * If the action is "Unlock", the device's state changes to UnlockedState.
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "Unlock").
 */
void LockedState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Unlock") {
        device->setState(std::make_shared<UnlockedState>());
    }
}


/**
 * @brief Returns the status of the device in the "Locked" state.
 * 
 * @return A string "locked" representing the current status of the device.
 */
std::string LockedState::getStatus() const {
    return "locked";
}
