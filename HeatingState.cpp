// Class implementation for Component 1 - State (ConcreteState)

/**
 * @file HeatingState.cpp
 * @brief Implementation of the HeatingState class methods.
 * 
 * This file provides the implementation of the HeatingState class, specifically
 * defining the behavior when a device is in the "heating" state and handling the
 * transition to the "cooling" state when needed.
 */

#include "HeatingState.h"
#include "SmartDevice.h"
#include "CoolingState.h"


/**
 * @brief Handles the action when the device is in the "Heating" state.
 * 
 * If the action is "Cool", the device's state changes to CoolingState.
 * 
 * @param device A shared pointer to the SmartDevice object.
 * @param action The action to be performed (e.g., "Cool").
 */
void HeatingState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Cool") {
        device->setState(std::make_shared<CoolingState>());
    }
}


/**
 * @brief Returns the status of the device in the "Heating" state.
 * 
 * @return A string "heating" representing the current status of the device.
 */
std::string HeatingState::getStatus() const {
    return "heating";
}
