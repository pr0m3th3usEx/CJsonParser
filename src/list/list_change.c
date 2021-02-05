/*
** EPITECH PROJECT, 2019
** PSU_tetris_2019
** File description:
** list_change.c
*/

#include <stdlib.h>
#include "list.h"

void list_change_from_tag(list_t *list, void *element, char const *tag)
{
    while (list != NULL) {
        if (strcmp(list->tag, tag) == 0) {
            list->element = element;
            break;
        }
        list = list->next;
    }
}

void list_change_from_index(list_t *list, void *element, int index)
{
    int i = 0;

    while (list != NULL) {
        if (index == i) {
            list->element = element;
            break;
        }
        list = list->next;
        i++;
    }
}