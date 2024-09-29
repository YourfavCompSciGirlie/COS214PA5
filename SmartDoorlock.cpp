// Class implementation for Component 1 - Composite (Leaf)

#include "SmartDoorlock.h"
#include "LockedState.h"
#include "UnlockedState.h"

SmartDoorlock::SmartDoorlock() : SmartDevice("SmartDoorlock") {
    // Initialize the DoorLock with an UnlockedState
    this->setState(std::make_shared<UnlockedState>());
}

void SmartDoorlock::performAction(const std::string& action) {
    // Delegate action to the current state
    state->performAction(shared_from_this(), action);
}

std::string SmartDoorlock::getStatus() const {
    return state->getStatus(); // Return the current state status
}

std::string SmartDoorlock::getDeviceType() const {
    return "SmartDoorLock";
}
