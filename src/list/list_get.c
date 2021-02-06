/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include <stdlib.h>
#include "list.h"
#include <string.h>

void *list_get_from_index(list_t *list, int index)
{
    int i = 0;

    while (list != NULL) {
        if (i == index)
            return (list->element);
        list = list->next;
        i++;
    }
    return NULL;
}

void *list_get_from_tag(list_t *list, char const *tag)
{
    while (list != NULL) {
        if (strcmp(tag, list->tag) == 0)
            return (list->element);
        list = list->next;
    }
    return NULL;
}
