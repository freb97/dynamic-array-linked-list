#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>
#include "modules.h"

typedef struct {
    Module* modules;
    size_t size;
    size_t used;
} DynamicModulesArray;

DynamicModulesArray construct_dynamic_modules_array();

void extend_dynamic_modules_array(DynamicModulesArray* array);

void push_back_module(DynamicModulesArray* array, Module* module);

void destruct_dynamic_modules_array(DynamicModulesArray* array);

#endif // DYNARRAY_H