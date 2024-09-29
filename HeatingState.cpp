// Class implementation for Component 1 - State (ConcreteState)

#include "HeatingState.h"
#include "SmartDevice.h"
#include "CoolingState.h"

void HeatingState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Cool") {
        device->setState(std::make_shared<CoolingState>());
    }
}

std::string HeatingState::getStatus() const {
    return "heating";
}
