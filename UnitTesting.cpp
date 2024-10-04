#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <memory>
#include <sstream>
#include <iostream>

#include "Alarm.h"
#include "CoolingState.h"
#include "HeatingState.h"
#include "SmartDevice.h"
#include "SmartThermostat.h"
#include "Dehumidifier.h"

// #include "SmartLight.h"
// #include "SmartDoorlock.h"
// #include "SmartThermostat.h"
// #include "SmartThermostatIntegrator.h"
// #include "LegacyThermostat.h"
// #include "House.h"
// #include "Room.h"

// TEST_CASE("State Pattern - SmartLight Test") {
//     std::shared_ptr<SmartLight> smartLight = std::make_shared<SmartLight>();

//     // Test turning on the light
//     smartLight->performAction("ToggleOn");
//     CHECK(smartLight->getStatus() == "on");

//     // Test turning off the light
//     smartLight->performAction("ToggleOff");
//     CHECK(smartLight->getStatus() == "off");
// }

// TEST_CASE("State Pattern - SmartDoorLock Test") {
//     std::shared_ptr<SmartDoorlock> smartDoorLock = std::make_shared<SmartDoorlock>();

//     // Test locking the door
//     smartDoorLock->performAction("Lock");
//     CHECK(smartDoorLock->getStatus() == "locked");

//     // Test unlocking the door
//     smartDoorLock->performAction("Unlock");
//     CHECK(smartDoorLock->getStatus() == "unlocked");
// }

// TEST_CASE("Composite Pattern - Room and House Test") {
//     // Create a house and a room
//     auto myHouse = std::make_shared<House>("My Smart House");
//     auto livingRoom = std::make_shared<Room>("Living Room");
//     myHouse->add(livingRoom);

//     // Add devices to the living room
//     auto smartLight = std::make_shared<SmartLight>();
//     livingRoom->add(smartLight);

//     // Test action on the light
//     smartLight->performAction("ToggleOn");
//     CHECK(livingRoom->getStatus().find("on") != std::string::npos); // Check if status contains "on"

//     // Test removing a device from the room
//     livingRoom->remove(smartLight);
//     CHECK(livingRoom->getStatus().find("off") != std::string::npos); // Light is no longer on
// }

// TEST_CASE("Adapter Pattern - Legacy Thermostat Integration") {
//     // Create a LegacyThermostat
//     auto legacyThermostat = std::make_shared<LegacyThermostat>();
//     SmartThermostatIntegrator smartThermostat(legacyThermostat);

//     // Test setting temperature
//     smartThermostat.setTemperature(23.0f);
//     CHECK(smartThermostat.getTemperature() == 23.0f);

//     // Test performing an action
//     smartThermostat.performAction("IncreaseTemperature");
//     CHECK(smartThermostat.getTemperature() == 24.0f);
// }



/**
 * @brief Test suite for the Alarm class.
 */
TEST_CASE("Testing Alarm class functionality") {

    Alarm alarm;

    SUBCASE("Testing update method with motion detected") {
        std::ostringstream oss;
        std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save original buffer
        std::cout.rdbuf(oss.rdbuf()); // Redirect cout to oss

        alarm.update("motion", "detected");
        std::cout.rdbuf(originalCoutBuffer); // Reset cout

        CHECK(oss.str() == "SmartAlarm: Motion detected! Sounding alarm.\n");
    }

    SUBCASE("Testing update method with motion clear") {
        std::ostringstream oss;
        std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save original buffer
        std::cout.rdbuf(oss.rdbuf()); // Redirect cout to oss

        alarm.update("motion", "clear");
        std::cout.rdbuf(originalCoutBuffer); // Reset cout

        CHECK(oss.str() == "SmartAlarm: Motion clear. Alarm deactivated.\n");
    }

    SUBCASE("Testing execute method") {
        std::ostringstream oss;
        std::streambuf* originalCoutBuffer = std::cout.rdbuf(); // Save original buffer
        std::cout.rdbuf(oss.rdbuf()); // Redirect cout to oss

        alarm.execute();
        std::cout.rdbuf(originalCoutBuffer); // Reset cout

        CHECK(oss.str() == "SmartAlarm: Executing alarm activation/deactivation based on sensor notification.\n");
    }
}

/**
 * @brief Test suite for the CoolingState class.
 */
TEST_SUITE("CoolingState") {

    TEST_CASE("Initial status of SmartThermostat should be 'cooling'") {
        // Create a SmartThermostat device
        std::shared_ptr<SmartThermostat> thermostat = std::make_shared<SmartThermostat>();
        
        // The initial state should be CoolingState
        CHECK(thermostat->getStatus() == "cooling");
    }

    TEST_CASE("Perform 'Heat' action switches state to HeatingState") {
        // Create a SmartThermostat device
        std::shared_ptr<SmartThermostat> thermostat = std::make_shared<SmartThermostat>();
        
        // Perform the action to switch to HeatingState
        thermostat->performAction("Heat");

        // After performing "Heat", the status should change to "heating"
        CHECK(thermostat->getStatus() == "heating");
    }

    TEST_CASE("Performing an unrecognized action keeps the thermostat in CoolingState") {
        // Create a SmartThermostat device
        std::shared_ptr<SmartThermostat> thermostat = std::make_shared<SmartThermostat>();
        
        // Perform an unrecognized action
        thermostat->performAction("InvalidAction");

        // The state should remain as CoolingState
        CHECK(thermostat->getStatus() == "cooling");
    }
}

/**
 * @brief Test suite for the Dehumidifier class.
 */
TEST_SUITE("Dehumidifier") {
    
    TEST_CASE("Dehumidifier activates on high humidity") {
        // Redirect output to a stringstream to capture it for testing
        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        
        // Create a Dehumidifier instance
        std::shared_ptr<Dehumidifier> dehumidifier = std::make_shared<Dehumidifier>();
        
        // Update with high humidity
        dehumidifier->update("humidity", "high");

        // Check the output
        CHECK(output.str() == "Dehumidifier: High humidity detected! Activating dehumidifier.\n");
        
        // Restore the original cout buffer
        std::cout.rdbuf(oldCoutBuffer);
    }

    TEST_CASE("Dehumidifier deactivates on low humidity") {
        // Redirect output to a stringstream to capture it for testing
        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        
        // Create a Dehumidifier instance
        std::shared_ptr<Dehumidifier> dehumidifier = std::make_shared<Dehumidifier>();
        
        // Update with low humidity
        dehumidifier->update("humidity", "low");

        // Check the output
        CHECK(output.str() == "Dehumidifier: Humidity at normal level. Deactivating dehumidifier.\n");
        
        // Restore the original cout buffer
        std::cout.rdbuf(oldCoutBuffer);
    }

    TEST_CASE("Dehumidifier does nothing on unrelated sensor type") {
        // Redirect output to a stringstream to capture it for testing
        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        
        // Create a Dehumidifier instance
        std::shared_ptr<Dehumidifier> dehumidifier = std::make_shared<Dehumidifier>();
        
        // Update with an unrelated sensor type
        dehumidifier->update("temperature", "high");

        // Check that there's no output for unrelated sensor type
        CHECK(output.str() == "");
        
        // Restore the original cout buffer
        std::cout.rdbuf(oldCoutBuffer);
    }

    TEST_CASE("Dehumidifier executes humidity control action") {
        // Redirect output to a stringstream to capture it for testing
        std::ostringstream output;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(output.rdbuf());
        
        // Create a Dehumidifier instance
        std::shared_ptr<Dehumidifier> dehumidifier = std::make_shared<Dehumidifier>();
        
        // Execute the dehumidifier action
        dehumidifier->execute();

        // Check the output
        CHECK(output.str() == "Dehumidifier: Executing humidity control based on sensor notification.\n");
        
        // Restore the original cout buffer
        std::cout.rdbuf(oldCoutBuffer);
    }
}

/**
 * @brief Test suite for the HeatingState class.
 */
TEST_SUITE("HeatingState") {

    TEST_CASE("HeatingState transitions to CoolingState on Cool action") {
        // Create a SmartThermostat instance
        std::shared_ptr<SmartThermostat> thermostat = std::make_shared<SmartThermostat>();
        
        // Set the state to HeatingState
        thermostat->setState(std::make_shared<HeatingState>());
        
        // Perform action to cool
        thermostat->performAction("Cool");
        
        // Check that the state is now CoolingState
        CHECK(thermostat->getStatus() == "cooling");
    }

    TEST_CASE("HeatingState returns correct status") {
        // Create a HeatingState instance
        HeatingState heatingState;

        // Check the status
        CHECK(heatingState.getStatus() == "heating");
    }

    TEST_CASE("HeatingState does not change state on unrelated action") {
        // Create a SmartThermostat instance
        std::shared_ptr<SmartThermostat> thermostat = std::make_shared<SmartThermostat>();
        
        // Set the state to HeatingState
        thermostat->setState(std::make_shared<HeatingState>());
        
        // Perform unrelated action
        thermostat->performAction("SomethingElse");
        
        // Check that the state remains HeatingState
        CHECK(thermostat->getStatus() == "heating");
    }
}

















