/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** list_destroy.c
*/

#include <stdlib.h>
#include "list.h"

void list_destroy(list_t **list, void (*element_destroy)())
{
    list_t *tmp;
    while ((*list) != NULL) {
        tmp = (*list)->next;
        destroy_from_list((*list)->element, element_destroy);
        free((*list)->tag);
        free(*list);
        *list = tmp;
    }
}