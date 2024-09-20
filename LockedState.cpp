// Class implementation for Component 1 - State (ConcreteState)

#include "LockedState.h"
#include "SmartDevice.h"
#include "UnlockedState.h"

void LockedState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Unlock") {
        device->setState(std::make_shared<UnlockedState>());
    }
}

std::string LockedState::getStatus() const {
    return "locked";
}
