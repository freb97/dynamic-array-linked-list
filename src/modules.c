#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[64];
    char abbrev[5];
    unsigned int workload;
    unsigned int credits;
    unsigned int semester;
    unsigned int duration;
} Module;

Module module_read() {
    Module module;

    int scan = scanf(" %64[^,],%5[^,],%u,%u,%u,%u",
        module.title,
        module.abbrev,
        &module.workload,
        &module.credits,
        &module.semester,
        &module.duration
    );

    return module;
}

void module_print(Module module) {
    printf("%s\n", module.title);
    printf("Kürzel  : %-9s", module.abbrev);
    printf("Workload: %-9u", module.workload);
    printf("Credits : %u\n", module.credits);
    printf("Semester: %-9u", module.semester);
    printf("Dauer   : %u\n", module.duration);
}