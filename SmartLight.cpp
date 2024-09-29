// Class implementation for Component 1 - Composite (Leaf)

#include "SmartLight.h"
#include "OnState.h"
#include "OffState.h"

SmartLight::SmartLight() : SmartDevice("SmartLight") {
    // Initialize the SmartLight with an OffState
    this->setState(std::make_shared<OffState>());
}

void SmartLight::performAction(const std::string& action) {
    // Delegate the action to the current state
    state->performAction(shared_from_this(), action);
}

std::string SmartLight::getStatus() const {
    return state->getStatus(); // Return the current state status (on/off)
}

std::string SmartLight::getDeviceType() const {
    return "SmartLight";
}
