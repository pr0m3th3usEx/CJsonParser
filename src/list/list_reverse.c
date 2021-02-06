/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include <stdlib.h>
#include "list.h"

list_t *list_reverse(list_t *head)
{
    list_t *tmp;
    list_t *prev = NULL;

    while (head != NULL) {
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}
