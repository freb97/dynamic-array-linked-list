#include <stdio.h>

#include "src/modules.h"
#include "src/dynarray.h"

int main() {
    // Construct array and allocate memory
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

    // Find index with abbreviation "MAT2" and print
    char searchWord[] = "MAT2";
    printf("\n\nSearching for %s...\n", searchWord);
    unsigned int index = find_module_index(&array, searchWord);
    printf("Index: %u\n", index);
    module_print(array.modules[index]);
    
    // Save module "MAT1" for later
    Module mat1 = array.modules[12];

    // Erase module "MAT1" (index 12)
    erase_module(&array, 12);

    // Add module "MAT1" to index 3
    insert_module(&array, 3, &mat1);

    // Print all modules in array
    printf("\n\n");
    for (int i = 0; i < array.used; i++) {
        module_print(array.modules[i]);
    }

    // Destruct array and free allocated memory
    destruct_dynamic_modules_array(&array);

    return 0;
}