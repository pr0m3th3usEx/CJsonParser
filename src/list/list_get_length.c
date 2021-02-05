/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** list_get_length.c
*/

#include <stdlib.h>
#include "list.h"

int list_get_length(list_t *list)
{
    int i;
    for (i = 0; list != NULL; i += 1, list = list->next);
    return i;
}