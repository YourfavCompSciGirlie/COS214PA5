// Class definition for Component 1 - State (ConcreteState)

#ifndef HEATINGSTATE_H
#define HEATINGSTATE_H

#include "DeviceState.h"

class HeatingState : public DeviceState {

    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // HEATINGSTATE_H
