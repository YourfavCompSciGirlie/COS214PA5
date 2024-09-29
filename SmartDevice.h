#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <memory>

// Forward declare DeviceState to avoid circular dependency
class DeviceState;

class SmartDevice : public std::enable_shared_from_this<SmartDevice> {

    protected:
        std::shared_ptr<DeviceState> state; // Smart pointer to the current state
        std::string deviceType;             // Type of device (e.g., "SmartLight", "SmartDoorLock", etc.)

    public:
        SmartDevice(const std::string& type); // Constructor to initialize device type and state
        virtual ~SmartDevice() = default;

        // State management
        void setState(const std::shared_ptr<DeviceState>& newState);

        // Concrete methods to be used by device subclasses
        virtual void performAction(const std::string& action);
        virtual std::string getStatus() const;
        virtual std::string getDeviceType() const; // Each device specifies its own type
};

#endif // SMARTDEVICE_H
