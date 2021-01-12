#include <stdio.h>
#include <stdlib.h>

#include "modules.h"

Module* module_read() {
    // Initialize module and allocate memory
    Module *module = (Module*) malloc(sizeof(Module));

    // Scan for input and pass to the module
    int scan = scanf(" %64[^,],%5[^,],%u,%u,%u,%u",
        module->title,
        module->abbrev,
        &module->workload,
        &module->credits,
        &module->semester,
        &module->duration
    );

    // Check input validity and destroy module if not valid
    if (scan != 6) {
        free(module);
        return NULL;
    }

    // Return module
    return module;
}

void module_print(Module module) {
    // Print all data from the given module
    printf("%s\n", module.title);
    printf("Kürzel  : %-9s", module.abbrev);
    printf("Workload: %-9u", module.workload);
    printf("Credits : %u\n", module.credits);
    printf("Semester: %-9u", module.semester);
    printf("Dauer   : %u\n", module.duration);
}