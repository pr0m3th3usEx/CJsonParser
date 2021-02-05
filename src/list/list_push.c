/*
** EPITECH PROJECT, 2019
** Runner
** File description:
** push_in.c
*/

#include <stdlib.h>
#include "list.h"

char *m_strdup(char const *src);

void list_push(list_t **head, void *element, char *tag)
{
    list_t *n_element = malloc(sizeof(list_t));

    if (!n_element)
        return;
    n_element->element = element;
    n_element->next = *head;
    n_element->tag = (!tag) ? NULL : m_strdup(tag);
    *head = n_element;
}