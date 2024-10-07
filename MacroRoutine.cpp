/**
 *
 * @file MacroRoutine..cpp
 * @brief Command to lock all doors in a smart door lock system.
 */

#include "MacroRoutine.h"
#include <algorithm> // for std::remove
#include "Device.h"

// Static member definition for storing saved macros
std::map<std::string, MacroRoutine *> MacroRoutine::savedMacros;

/**
 *
 * @file MacroRoutine.cpp
 * @brief Constructs a MacroRoutine with a given name.
 *
 * @param name Name of the macro routine.
 */
MacroRoutine::MacroRoutine(const std::string &name) : name(name) {}

/**
 * @brief Adds a procedure to the macro routine.
 *
 * This method appends a Device to the internal list of Devices.
 *
 * @param Device Pointer to the Device to be added.
 */
void MacroRoutine::addProcedure(Device *device)
{
    this->device.push_back(device);
    std::cout << "Added procedure to Macro: " << name << std::endl;
}

/**
 * @brief Removes a procedure from the macro routine.
 *
 * This method searches for the specified Device in the internal list
 * and removes it if found.
 *
 * @param Device Pointer to the Device to be removed.
 */
void MacroRoutine::removeProcedure(Device *device)
{
    auto it = std::remove(this->device.begin(), this->device.end(), device);
    if (it != this->device.end())
    {
        this->device.erase(it, this->device.end());
        std::cout << "Removed procedure from Macro: " << name << std::endl;
    }
    else
    {
        std::cout << "Procedure not found in Macro: " << name << std::endl;
    }
}

/**
 * @brief Executes all procedures in the macro routine.
 *
 * This method loops through all added Devices and calls their `execute()` methods.
 */
void MacroRoutine::execute()
{
    std::cout << "Executing Macro: " << name << std::endl;
    for (auto &Device : device)
    {
        Device->execute(); // Execute each Device
    }
}

/**
 * @brief Saves a macro routine for future use.
 *
 * This method associates a name with a MacroRoutine for later retrieval.
 *
 * @param name Name under which the macro will be saved.
 * @param macro Pointer to the MacroRoutine to save.
 */
void MacroRoutine::saveMacro(const std::string &name, MacroRoutine *macro)
{
    savedMacros[name] = macro;
    std::cout << "Macro " << name << " saved for future use." << std::endl;
}

/**
 * @brief Loads a saved macro routine.
 *
 * This method retrieves a MacroRoutine based on the given name.
 *
 * @param name Name of the macro to load.
 * @return Pointer to the loaded MacroRoutine, or nullptr if not found.
 */
MacroRoutine *MacroRoutine::loadMacro(const std::string &name)
{
    if (savedMacros.find(name) != savedMacros.end())
    {
        std::cout << "Loading Macro: " << name << std::endl;
        return savedMacros[name];
    }
    else
    {
        std::cout << "Error: Macro " << name << " not found!" << std::endl;
        return nullptr;
    }
}

/**
 * @brief Destructor for MacroRoutine.
 *
 * Cleans up resources used by the MacroRoutine. Note:
 * The deletion of Devices is commented out to prevent extra deallocations.
 */
MacroRoutine::~MacroRoutine()
{
    // was causing extra deallocations
    // for (auto Device : this->Device) {
    //     delete Device;
    // }
    std::cout << "MacroRoutine " << name << " destroyed and procedures cleaned up." << std::endl;
}

/**
 * @brief Lists all saved macros to the console.
 *
 * This method provides a debug output of all currently saved macros.
 * If no macros are saved, it indicates that as well.
 */
void MacroRoutine::listSavedMacros()
{
    std::cout << "Saved Macros:" << std::endl;
    for (const auto &macro : savedMacros)
    {
        std::cout << "- " << macro.first << std::endl;
    }
    if (savedMacros.empty())
    {
        std::cout << "No macros saved." << std::endl;
    }
}
