// Class implementation for Component 1 - Composite (Leaf)

#include "SmartThermostat.h"
#include "CoolingState.h"
#include "HeatingState.h"

SmartThermostat::SmartThermostat() : SmartDevice("SmartThermostat") {
    // Initialize the Thermostat with a CoolingState
    this->setState(std::make_shared<CoolingState>());
}

void SmartThermostat::performAction(const std::string& action) {
    // Delegate action to the current state
    state->performAction(shared_from_this(), action);
}

std::string SmartThermostat::getStatus() const {
    return state->getStatus(); // Return the current state status
}

std::string SmartThermostat::getDeviceType() const {
    return "SmartThermostat";
}
