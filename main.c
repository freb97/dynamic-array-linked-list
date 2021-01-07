#include <stdio.h>

#include "src/modules.h"
#include "src/dynarray.h"

int main() {
    DynamicModulesArray array = construct_dynamic_modules_array();

    // Read modules as long as valid input is given
    while(1) {
        Module *module = module_read();

        if (module == NULL) {
            break;
        }

        // Push modules into array
        push_back_module(&array, module);
    }
    
    // Print all modules in array
    for (int i = 0; i < array.used; i++) {
        module_print(array.modules[i]);
    }

    // Find index with abbreviation "MAT2" and print
    char searchWord[] = "MAT2";
    printf("\n\nSearching for %s...\n", searchWord);
    unsigned int index = find_module_index(&array, searchWord);
    printf("Index: %u\n", index);
    module_print(array.modules[index]);

    // Destruct array
    destruct_dynamic_modules_array(&array);

    return 0;
}