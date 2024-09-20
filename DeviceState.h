// Class defintion for Component 1 - State (State)

#ifndef DEVICESTATE_H
#define DEVICESTATE_H

#include <memory>
#include <string>

class SmartDevice; // Forward declaration

class DeviceState {

    public:
        virtual void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) = 0;
        virtual std::string getStatus() const = 0;
        virtual ~DeviceState() = default;
};

#endif // DEVICESTATE_H