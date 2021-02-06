/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** list_exists.c
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