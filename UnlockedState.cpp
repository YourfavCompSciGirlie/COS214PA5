// Class implementation for Component 1 - State (ConcreteState)

#include "UnlockedState.h"
#include "SmartDevice.h"
#include "LockedState.h"

void UnlockedState::performAction(std::shared_ptr<SmartDevice> device, const std::string& action) {
    if (action == "Lock") {
        device->setState(std::make_shared<LockedState>());
    }
}

std::string UnlockedState::getStatus() const {
    return "unlocked";
}
