/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include <stdlib.h>
#include "list.h"

void destroy_from_list(void *element, void (*element_destroy)())
{
    if (!element_destroy)
        return;
    (*element_destroy)(element);
}

void list_remove_from_index(list_t **list, int index, void (*element_destroy)())
{
    int i = 0;
    list_t *prev = NULL, *curr = *list, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        if (i == index) {
            (*element_destroy)(curr->element);
            if (prev == NULL)
                *list = next;
            else
                prev->next = next;
        }
        prev = curr;
        curr = next;
        i += 1;
    }
}
void list_remove_from_tag(list_t **list, char const *tag, void
(*element_destroy)())
{
    list_t *prev = NULL, *curr = *list, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        if (strcmp(tag, curr->tag) == 0) {
            destroy_from_list(curr->element, element_destroy);
            if (prev == NULL)
                *list = next;
            else {
                prev->next = next;
            }
        }
        prev = curr;
        curr = next;
    }
}