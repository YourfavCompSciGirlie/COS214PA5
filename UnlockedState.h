// Class definition for Component 1 - State (ConcreteState)

#ifndef UNLOCKEDSTATE_H
#define UNLOCKEDSTATE_H

#include "DeviceState.h"

class UnlockedState : public DeviceState {

    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // UNLOCKEDSTATE_H
