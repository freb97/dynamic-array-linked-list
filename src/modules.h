#ifndef MODULES_H
#define MODULES_H

typedef struct {
    char title[64];
    char abbrev[5];
    unsigned int workload;
    unsigned int credits;
    unsigned int semester;
    unsigned int duration;
} Module;

Module module_read();

void module_print(Module module);

#endif /* MODULES_H */