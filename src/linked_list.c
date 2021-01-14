#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "modules.h"

LinkedModulesListElement* construct_linked_modules_list_element() {
    LinkedModulesListElement *element = malloc(sizeof(LinkedModulesListElement));

    element->module = NULL;
    element->next = NULL;
    element->prev = NULL;

    return element;
}

void destruct_linked_modules_list_element(LinkedModulesListElement* element) {
    if (element->module != NULL) {
        free(element->module);
        element->module = NULL;
    }

    element->next = NULL;
    element->prev = NULL;
}

LinkedModulesList* construct_linked_modules_list() {
    LinkedModulesList* list = malloc(sizeof(LinkedModulesList));

    list->first = NULL;
    list->last = NULL;

    return list;
}

void destruct_linked_modules_list(LinkedModulesList* list) {
    LinkedModulesListElement *element = list->first;

    while(1) {
        if (element->next != NULL) {
            element = element->next;
            destruct_linked_modules_list_element(element->prev);
        } else {
            destruct_linked_modules_list_element(element);
            break;
        }
    }

    free(list);
}

void list_push_back_module(LinkedModulesList* list, Module* module) {
    LinkedModulesListElement* element = construct_linked_modules_list_element();

    element->module = module;
    element->prev = list->last;

    if (element->prev != NULL) {
        element->prev->next = element;
    }

    list->last = element;

    if (list->first == NULL) {
        list->first = element;
    }
}

LinkedModulesListElement* find_list_modules_element(LinkedModulesList* list, char* abbreviation) {
    LinkedModulesListElement *element = list->first;

    while(1) {
        if (strcmp(abbreviation, element->module->abbrev) != 0) {
            if (element->next != NULL) {
                element = element->next;
            } else {
                break;
            }
        } else {
            return element;
        }
    }

    return NULL;
}

void erase_linked_modules_list_element(LinkedModulesList* list, LinkedModulesListElement* element) {
    element->prev->next = element->next;
    element->next->prev = element->prev;

    destruct_linked_modules_list_element(element);
}

void insert_module_after(LinkedModulesList* list, LinkedModulesListElement* element, Module* module) {
    LinkedModulesListElement *new_element = construct_linked_modules_list_element();

    new_element->module = module;
    new_element->prev = element;
    new_element->next = element->next;

    if (element->next != NULL) {
        element->next->prev = new_element;
        element->next = new_element;
    }

    if (new_element->next == NULL) {
        list->last = new_element;
    }
}