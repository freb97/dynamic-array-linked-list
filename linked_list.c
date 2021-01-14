#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/modules.h"
#include "src/linked_list.h"

int main() {
    // Construct list and allocate memory
    LinkedModulesList *list = construct_linked_modules_list();

    // Read modules as long as valid input is given
    while(1) {
        Module *module = module_read();

        if (module == NULL) {
            break;
        }

        // Push module into list
        list_push_back_module(list, module);
    }

    // Find element containing the module with abbreviation "MAT1"
    LinkedModulesListElement *element = find_list_modules_element(list, "MAT1");

    // Erase element with module "MAT1"
    erase_linked_modules_list_element(list, element);

    // Construct new module "FRED" outside of normal module input
    Module *additional_module = (Module*) malloc(sizeof(Module));
    strcpy(additional_module->title, "Freds Programmierstübchen");
    strcpy(additional_module->abbrev, "FRED");
    additional_module->workload = 420;
    additional_module->credits = 69;
    additional_module->duration = 12;
    additional_module->semester = 1;

    // Insert module "FRED" after module "SLAB" in the list
    insert_module_after(list, find_list_modules_element(list, "SLAB"), additional_module);

    // Print all modules
    printf("\nPrinting all modules:\n");
    element = list->first;
    while(1) {
        if (element->next != NULL) {
            element = element->next;
            module_print(*element->prev->module);
        } else {
            module_print(*element->module);
            break;
        }
    }

    // Destruct list and free all allocated memory
    destruct_linked_modules_list(list);

    return 1;
}