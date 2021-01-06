#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <stddef.h>
#include "modules.h"

typedef struct {
    Module* modules;
    size_t size;
} DynamicModulesArray;

DynamicModulesArray construct_dynamic_modules_array();

void destruct_dynamic_modules_array(DynamicModulesArray* array);

#endif // DYNARRAY_H