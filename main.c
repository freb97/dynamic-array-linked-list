#include <stdio.h>

#include "src/modules.h"
#include "src/dynarray.h"

int main() {
    DynamicModulesArray array = construct_dynamic_modules_array();

    while(1) {
        Module *module = module_read();

        if (module == NULL) {
            break;
        }

        push_back_module(&array, module);
    }
    
    for (int i = 0; i < array.used; i++) {
        module_print(array.modules[i]);
    }

    destruct_dynamic_modules_array(&array);

    return 0;
}