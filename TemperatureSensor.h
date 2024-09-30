//Class defintion for Component 4  - Observer(ConcreteSubject)

#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.h"


class TemperatureSensor : public Sensor {
private:
    std::vector<Device*> devices;
    std::string sensorState = "normal"; // Initial temperature state

public:
    void addDevice(Device* device) override;
    void removeDevice(Device* device) override;
    void notifyDevices() override;

    // Simulate high temperature event
    void detectHighTemperature();
    void detectLowTemperature();
};

#endif 
