/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include <stdlib.h>
#include "list.h"

void list_concat(list_t **dest, list_t *src)
{
    list_t *last_element_src = src;

    while (last_element_src->next != NULL) {
        last_element_src = last_element_src->next;
    }
    last_element_src->next = *dest;
    *dest = src;
}