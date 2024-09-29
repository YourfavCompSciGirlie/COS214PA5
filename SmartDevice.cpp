#include "SmartDevice.h"
#include "OffState.h"

SmartDevice::SmartDevice(const std::string& type) : deviceType(type) {
    // Initialize the device with a default state (OffState)
    this->state = std::make_shared<OffState>();
}

void SmartDevice::setState(const std::shared_ptr<DeviceState>& newState) {
    state = newState;
}

void SmartDevice::performAction(const std::string& action) {
    // Delegate the action to the current state
    state->performAction(shared_from_this(), action);
}

std::string SmartDevice::getStatus() const {
    return state->getStatus();
}

std::string SmartDevice::getDeviceType() const {
    return deviceType;
}