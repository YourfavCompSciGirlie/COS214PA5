// Class definition for Component 1 - Composite (Leaf)

#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

class Doorlock : public SmartDevice {

    public:
        Doorlock();
        
        void performAction(const std::string& action) override;
        std::string getStatus() const override;
        std::string getDeviceType() const override;
};

#endif // DOORLOCK_H
