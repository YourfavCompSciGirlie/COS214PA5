// Class implementation for Component 1 - State (ConcreteState)

#include "OffState.h"
#include "SmartDevice.h"
#include "OnState.h"

void OffState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "ToggleOn") {
        device->setState(std::make_shared<OnState>());
    }
}

std::string OffState::getStatus() const {
    return "off";
}
