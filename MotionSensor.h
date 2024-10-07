#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"

/**
 * @file MotionSensor.h
 * @brief Concrete Subject class that represents a motion sensor in an Observer pattern.
 *
 * The MotionSensor class is responsible for detecting motion and notifying all registered
 * devices (observers) of any changes in motion state (e.g., detected or clear).
 */
class MotionSensor : public Sensor
{
private:
    std::vector<Device *> devices;     ///< List of registered devices (observers).
    std::string sensorState = "clear"; ///< Initial state of the motion sensor.

public:
    /**
     * @brief Registers a device to receive motion notifications.
     *
     * @param device Pointer to the device that should be notified of motion changes.
     */
    void addDevice(Device *device) override;

    /**
     * @brief Unregisters a device so it no longer receives motion notifications.
     *
     * @param device Pointer to the device to be removed from the notification list.
     */
    void removeDevice(Device *device) override;

    /**
     * @brief Notifies all registered devices of motion state changes.
     *
     * This method iterates through all registered devices and calls their update function,
     * passing the current motion state.
     */
    void notifyDevices() override;

    /**
     * @brief Simulates the detection of motion by the sensor.
     *
     * Changes the sensor state to "detected" and notifies all registered devices.
     */
    void detectMotion();

    /**
     * @brief Simulates the clearing of motion detection by the sensor.
     *
     * Changes the sensor state to "clear" and notifies all registered devices.
     */
    void clearMotion();
};

#endif // MOTIONSENSOR_H
