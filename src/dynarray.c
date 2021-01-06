#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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

    printf("extend");
}

void destruct_dynamic_modules_array(DynamicModulesArray* array) {
    if (array->modules != NULL) {
        free(array->modules);
    }

    array->modules = NULL;
    array->used = 0;
    array->size = 0;
}