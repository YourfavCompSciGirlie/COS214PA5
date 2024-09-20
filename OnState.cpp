// Class implementation for Component 1 - State (ConcreteState)

#include "OnState.h"
#include "SmartDevice.h"
#include "OffState.h"

void OnState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Toggle") {
        device->setState(std::make_shared<OffState>());
    }
}

std::string OnState::getStatus() const {
    return "on";
}
