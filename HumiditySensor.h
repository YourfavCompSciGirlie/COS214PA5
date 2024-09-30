//Class defintion for Component 4  - Observer(ConcreteSubject)


#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.h"


class HumiditySensor : public Sensor {
private:
    std::vector<Device*> devices;
    std::string sensorState = "normal"; // Initial humidity state

public:
    void addDevice(Device* device) override;
    void removeDevice(Device* device) override;
    void notifyDevices() override;

    // Simulate high humidity event
    void detectHighHumidity();
    void detectLowHumidity();
};

#endif 
