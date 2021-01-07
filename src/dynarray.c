#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "modules.h"

typedef struct {
    Module* modules;
    size_t size;
    size_t used;
} DynamicModulesArray;

DynamicModulesArray construct_dynamic_modules_array() {
    DynamicModulesArray array;
 
    array.size = 4;
    array.used = 0;

    array.modules = (Module*) malloc(array.size * sizeof(Module));
 
    return array;
}

void extend_dynamic_modules_array(DynamicModulesArray* array) {
    array->size *= 2;
    array->modules = realloc(array->modules, array->size * sizeof(Module));
}

void push_back_module(DynamicModulesArray* array, Module* module) {
    if (array->used == array->size) {
        extend_dynamic_modules_array(array);
    }

    array->modules[array->used++] = *module;
}

unsigned int find_module_index(DynamicModulesArray* array, char* abbreviation) {
    for (int i = 0; i < array->used; i++) {
        if (strcmp(abbreviation, array->modules[i].abbrev) == 0) {
            return i;
        }
    }

    return array->used;
}

void erase_module(DynamicModulesArray* array, unsigned int index) {
    for (int i = index; i < array->used - 1; i++) {
        array->modules[i] = array->modules[i + 1];
    }

    array->used--;
}

void insert_module(DynamicModulesArray* array, unsigned int index, Module* module) {
    if (index + 1 > array->size) {
        extend_dynamic_modules_array(array);
    }

    for (int i = array->used; i >= index; i--) {
        array->modules[i + 1] = array->modules[i];
    }

    array->modules[index] = *module;
    array->used++;
}

void destruct_dynamic_modules_array(DynamicModulesArray* array) {
    if (array->modules != NULL) {
        free(array->modules);
    }

    array->modules = NULL;
    array->used = 0;
    array->size = 0;
}