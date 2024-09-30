//Class defintion for Component 4  - Observer(ConcreteSubject)

#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"

// Concrete Subject (MotionSensor)
class MotionSensor : public Sensor 
{
private:
    std::vector<Device*> devices; // List of registered devices (observers)
    std::string sensorState = "clear"; // Initial state of the sensor

public:
    void addDevice(Device* device) override;
    void removeDevice(Device* device) override;
    void notifyDevices() override;

    // Simulate motion detection event
    void detectMotion();
    void clearMotion();
};

#endif // MOTIONSENSOR_H
