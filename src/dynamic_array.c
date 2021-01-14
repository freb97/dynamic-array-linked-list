#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"
#include "dynamic_array.h"

DynamicModulesArray construct_dynamic_modules_array() {
    // Construct dynamic modules array and allocate memory with for an initial capacity of 4
    DynamicModulesArray array = {
        .size = 4,
        .used = -1,
        .modules = (Module*) malloc(4 * sizeof(Module))
    };
    
    // Return constructed array
    return array;
}

void extend_dynamic_modules_array(DynamicModulesArray* array) {
    // Double array size
    array->size *= 2;

    // Initialize and allocate memory for new modules array
    Module *modules = (Module*) malloc(array->size * sizeof(Module));

    // Iterate array content and copy to new modules array
    for (int i = 0; i <= array->used; i++) {
        modules[i] = array->modules[i];
    }

    // Free memory from old modules array
    free(array->modules);

    // Assign new modules array
    array->modules = modules;
}

void push_back_module(DynamicModulesArray* array, Module* module) {
    // Check if array is full and extend if necessary
    if (array->used + 1 == array->size) {
        extend_dynamic_modules_array(array);
    }

    // Pass module to array and add +1 to the number of modules in array
    array->modules[array->used++] = *module;
}

unsigned int find_module_index(DynamicModulesArray* array, char* abbreviation) {
    // Iterate array content and compare module abbreviation with given abbreviation
    for (int i = 0; i <= array->used; i++) {
        if (strcmp(abbreviation, array->modules[i].abbrev) == 0) {
            // Return index of found module
            return i;
        }
    }

    // Return number of modules in array 
    return array->used;
}

void erase_module(DynamicModulesArray* array, unsigned int index) {
    // Iterate through array and move all modules after index to its preceding position
    for (int i = index; i < array->used; i++) {
        array->modules[i] = array->modules[i + 1];
    }

    // Count number of modules in array -1;
    array->used--;
}

void insert_module(DynamicModulesArray* array, unsigned int index, Module* module) {
    // Check if array is full and extend if necessary
    if (array->used + 1 > array->size) {
        extend_dynamic_modules_array(array);
    }

    // Iterate through array backwards and move all modules after used to their next position
    for (int i = array->used + 1; i >= index; i--) {
        array->modules[i + 1] = array->modules[i];
    }

    // Insert module at index
    array->modules[index] = *module;

    // Count number of modules in array + 1
    array->used++;
}

void destruct_dynamic_modules_array(DynamicModulesArray* array) {
    // Check if array is nullpointer and free memory if possible
    if (array->modules != NULL) {
        free(array->modules);
    }

    // Set array to nullpointer
    array->modules = NULL;

    // Set number of modules in array and capacity of array to 0
    array->used = 0;
    array->size = 0;
}