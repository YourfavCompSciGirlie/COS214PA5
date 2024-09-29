// Class implementation for Component 1 - State (ConcreteState)

#include "CoolingState.h"
#include "SmartDevice.h"
#include "HeatingState.h"

void CoolingState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Heat") {
        device->setState(std::make_shared<HeatingState>());
    }
}

std::string CoolingState::getStatus() const {
    return "cooling";
}
