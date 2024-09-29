// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file OffState.cpp
 * @brief Implementation of the OffState class methods.
 * 
 * This file provides the implementation of the OffState class, specifically
 * defining the behavior when a device is in the "off" state and handling the
 * transition to the "on" state when needed.
 */

#include "OffState.h"
#include "SmartDevice.h"
#include "OnState.h"


/**
 * @brief Handles the action when the device is in the "Off" state.
 * 
 * If the action is "ToggleOn", the device's state changes to OnState.
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "ToggleOn").
 */
void OffState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "ToggleOn") {
        device->setState(std::make_shared<OnState>());
    }
}


/**
 * @brief Returns the status of the device in the "Off" state.
 * 
 * @return A string "off" representing the current status of the device.
 */
std::string OffState::getStatus() const {
    return "off";
}
