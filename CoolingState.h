// Class definition for Component 1 - State (ConcreteState)

#ifndef COOLINGSTATE_H
#define COOLINGSTATE_H

#include "DeviceState.h"

class CoolingState : public DeviceState {
    
    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // COOLINGSTATE_H
