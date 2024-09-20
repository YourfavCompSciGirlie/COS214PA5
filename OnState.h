// Class defintion for Component 1 - State (ConcreteState)

#ifndef ONSTATE_H
#define ONSTATE_H

#include "DeviceState.h"

class OnState : public DeviceState {
    
    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // ONSTATE_H
