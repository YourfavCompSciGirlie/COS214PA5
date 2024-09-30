#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <memory>

#include "SmartLight.h"
#include "SmartDoorlock.h"
#include "SmartThermostat.h"
#include "SmartThermostatIntegrator.h"
#include "LegacyThermostat.h"
#include "House.h"
#include "Room.h"

TEST_CASE("State Pattern - SmartLight Test") {
    std::shared_ptr<SmartLight> smartLight = std::make_shared<SmartLight>();

    // Test turning on the light
    smartLight->performAction("ToggleOn");
    CHECK(smartLight->getStatus() == "on");

    // Test turning off the light
    smartLight->performAction("ToggleOff");
    CHECK(smartLight->getStatus() == "off");
}

TEST_CASE("State Pattern - SmartDoorLock Test") {
    std::shared_ptr<SmartDoorlock> smartDoorLock = std::make_shared<SmartDoorlock>();

    // Test locking the door
    smartDoorLock->performAction("Lock");
    CHECK(smartDoorLock->getStatus() == "locked");

    // Test unlocking the door
    smartDoorLock->performAction("Unlock");
    CHECK(smartDoorLock->getStatus() == "unlocked");
}

TEST_CASE("Composite Pattern - Room and House Test") {
    // Create a house and a room
    auto myHouse = std::make_shared<House>("My Smart House");
    auto livingRoom = std::make_shared<Room>("Living Room");
    myHouse->add(livingRoom);

    // Add devices to the living room
    auto smartLight = std::make_shared<SmartLight>();
    livingRoom->add(smartLight);

    // Test action on the light
    smartLight->performAction("ToggleOn");
    CHECK(livingRoom->getStatus().find("on") != std::string::npos); // Check if status contains "on"

    // Test removing a device from the room
    livingRoom->remove(smartLight);
    CHECK(livingRoom->getStatus().find("off") != std::string::npos); // Light is no longer on
}

TEST_CASE("Adapter Pattern - Legacy Thermostat Integration") {
    // Create a LegacyThermostat
    auto legacyThermostat = std::make_shared<LegacyThermostat>();
    SmartThermostatIntegrator smartThermostat(legacyThermostat);

    // Test setting temperature
    smartThermostat.setTemperature(23.0f);
    CHECK(smartThermostat.getTemperature() == 23.0f);

    // Test performing an action
    smartThermostat.performAction("IncreaseTemperature");
    CHECK(smartThermostat.getTemperature() == 24.0f);
}
