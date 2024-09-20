// Class defintion for Component 1 - State (ConcreteState)

#ifndef OFFSTATE_H
#define OFFSTATE_H

#include "DeviceState.h"

class OffState : public DeviceState {
    
    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // OFFSTATE_H
