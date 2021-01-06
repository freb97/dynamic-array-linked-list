#include <stdio.h>

#include "src/modules.h"
#include "src/dynarray.h"

int main() {
    DynamicModulesArray array = construct_dynamic_modules_array();

    for (int i = 0; i < 15; i++) {
        Module module = module_read();

        push_back_module(&array, &module);
    }
    
    for (int ii = 0; ii < 15; ii++) {
        module_print(array.modules[ii]);
    }

    destruct_dynamic_modules_array(&array);

    return 0;
}