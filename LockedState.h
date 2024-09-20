// Class definition for Component 1 - State (ConcreteState)

#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include "DeviceState.h"

class LockedState : public DeviceState {

    public:
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;
        std::string getStatus() const override;
};

#endif // LOCKEDSTATE_H
