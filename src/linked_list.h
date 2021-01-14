#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "modules.h"

typedef struct LinkedModulesListElement {
    Module* module;
    struct LinkedModulesListElement* next;
    struct LinkedModulesListElement* prev;
} LinkedModulesListElement;

typedef struct {
    LinkedModulesListElement* first;
    LinkedModulesListElement* last;
} LinkedModulesList;

LinkedModulesListElement* construct_linked_modules_list_element();

void destruct_linked_modules_list_element(LinkedModulesListElement* element);

LinkedModulesList* construct_linked_modules_list();

void destruct_linked_modules_list(LinkedModulesList* list);

void list_push_back_module(LinkedModulesList* list, Module* module);

LinkedModulesListElement* find_list_modules_element(LinkedModulesList* list, char* abbreviation);

void erase_linked_modules_list_element(LinkedModulesList* list, LinkedModulesListElement* element);

void insert_module_after(LinkedModulesList* list, LinkedModulesListElement* element, Module* module);

#endif /* LINKED_LIST_H */