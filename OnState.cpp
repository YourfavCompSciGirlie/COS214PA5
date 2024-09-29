// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file OnState.cpp
 * @brief Implementation of the OnState class methods.
 * 
 * This file provides the implementation of the OnState class, specifically
 * defining the behavior when a device is in the "on" state and handling the
 * transition to the "off" state when needed.
 */

#include "OnState.h"
#include "SmartDevice.h"
#include "OffState.h"


/**
 * @brief Handles the action when the device is in the "On" state.
 * 
 * If the action is "ToggleOff", the device's state changes to OffState. 
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "ToggleOff").
 */
void OnState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "ToggleOff") {
        device->setState(std::make_shared<OffState>());
    }
}


/**
 * @brief Returns the status of the device in the "On" state.
 * 
 * @return A string "on" representing the current status of the device.
 */
std::string OnState::getStatus() const {
    return "on";
}
