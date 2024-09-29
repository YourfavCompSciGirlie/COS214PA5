#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include "SmartDevice.h"
#include <memory>
#include <string>

class SmartLight : public SmartDevice {
    
    public:
        SmartLight();
        
        void performAction(const std::string& action) override;
        std::string getStatus() const override;
        std::string getDeviceType() const override;
};

#endif // SMARTLIGHT_H
