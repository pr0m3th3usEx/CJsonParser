/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include <stdlib.h>
#include "list.h"

int list_get_length(list_t *list)
{
    int i;
    for (i = 0; list != NULL; i += 1, list = list->next);
    return i;
}