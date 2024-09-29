// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file CoolingState.cpp
 * @brief Implementation of the CoolingState class methods.
 * 
 * This file provides the implementation of the CoolingState class, specifically
 * defining the behavior when a device is in the "cooling" state and handling the
 * transition to the "heating" state when needed.
 */

#include "CoolingState.h"
#include "SmartDevice.h"
#include "HeatingState.h"


/**
 * @brief Handles the action when the device is in the "Cooling" state.
 * 
 * If the action is "Heat", the device's state changes to HeatingState.
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "Heat").
 */
void CoolingState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Heat") {
        device->setState(std::make_shared<HeatingState>());
    }
}


/**
 * @brief Returns the status of the device in the "Cooling" state.
 * 
 * @return A string "cooling" representing the current status of the device.
 */
std::string CoolingState::getStatus() const {
    return "cooling";
}
