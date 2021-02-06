/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "list.h"

bool list_exists(list_t *list, void *element)
{
    while (list) {
        if (list->element == element)
            return true;
        list = list->next;
    }
    return false;
}