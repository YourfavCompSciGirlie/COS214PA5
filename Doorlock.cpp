// Class implementation for Component 1 - Composite (Leaf)

#include "Doorlock.h"
#include "LockedState.h"
#include "UnlockedState.h"

Doorlock::Doorlock() {
    // Initialize the DoorLock with an UnlockedState
    this->setState(std::make_shared<UnlockedState>());
}

void Doorlock::performAction(const std::string& action) {
    // Delegate action to the current state
    state->performAction(shared_from_this(), action);
}

std::string Doorlock::getStatus() const {
    return state->getStatus(); // Return the current state status
}

std::string Doorlock::getDeviceType() const {
    return "DoorLock";
}
