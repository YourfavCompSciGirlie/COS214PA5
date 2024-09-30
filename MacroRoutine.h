// Class definition for Component 3 - Command (Invoker)

#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "Device.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>

/**
 * @brief Class representing a macro routine that can execute a series of Devices.
 * 
 * This class allows users to create macros composed of multiple Device procedures, 
 * providing functionality to add, remove, execute, save, and load macros.
 */
class MacroRoutine 
 {
private:
    std::vector<Device*> device;  ///< List of Device procedures in the macro.
    std::string name;                ///< Name of the macro routine.
    static std::map<std::string, MacroRoutine*> savedMacros; ///< Map of saved macros.

public:
    /**
     * @brief Constructs a MacroRoutine with a given name.
     * 
     * @param name Name of the macro routine.
     */
    MacroRoutine(const std::string& name);

    /**
     * @brief Adds a procedure to the macro routine.
     * 
     * @param Device Pointer to the Device to be added to the macro.
     */
    void addProcedure(Device* device);

    /**
     * @brief Removes a procedure from the macro routine.
     * 
     * @param Device Pointer to the Device to be removed from the macro.
     */
    void removeProcedure(Device* device);

    // Execute all procedures
    void execute();
    
    /**
     * @brief Saves a macro routine for future use.
     * 
     * @param name Name under which the macro will be saved.
     * @param macro Pointer to the MacroRoutine to save.
     */
    static void saveMacro(const std::string& name, MacroRoutine* macro);

    /**
     * @brief Loads a saved macro routine.
     * 
     * @param name Name of the macro to load.
     * @return Pointer to the loaded MacroRoutine, or nullptr if not found.
     */
    static MacroRoutine* loadMacro(const std::string& name);

    /**
     * @brief Destructor for MacroRoutine.
     * 
     * Cleans up resources used by the MacroRoutine.
     */
    ~MacroRoutine();

    /**
     * @brief Lists all saved macros to the console.
     * 
     * This method provides a debug output of all currently saved macros.
     */
    static void listSavedMacros(); ///< List all saved macros
};

#endif 
