#include <stdio.h>

#include "src/modules.h"
#include "src/dynarray.h"

int main() {
    Module module = module_read();

    module_print(module);

    return 0;
}