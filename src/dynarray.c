#include <stddef.h>
#include <stdlib.h>

#include "modules.h"

typedef struct {
    Module* modules;
    size_t size;
} DynamicModulesArray;

DynamicModulesArray construct_dynamic_modules_array() {
    DynamicModulesArray array;

    array.size = 0;
    array.modules = (Module*) malloc(sizeof(Module));

    return array;
}

void destruct_dynamic_modules_array(DynamicModulesArray* array) {
    if (array != NULL) {
        if (array->modules != NULL) {
            free(array->modules);
        }

        free(array);
    }
}