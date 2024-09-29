// Class definition for Component 1 - Composite (Leaf)

#ifndef SMARTDOORLOCK_H
#define SMARTDOORLOCK_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

class SmartDoorlock : public SmartDevice {

    public:
        SmartDoorlock();
        
        void performAction(const std::string& action) override;
        std::string getStatus() const override;
        std::string getDeviceType() const override;
};

#endif // SMARTDOORLOCK_H
