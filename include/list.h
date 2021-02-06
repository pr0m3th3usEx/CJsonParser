/*
** PR0M3TH3USEX PROJECT, 2019
*/

#ifndef _PR0METH3USEX_LIST_H
#define _PR0METH3USEX_LIST_H

#include <stdbool.h>
#include <string.h>

typedef struct linked_list
{
    char *tag;
    void *element;
    struct linked_list *next;
} list_t;

extern void list_push(list_t **head, void *element, char *tag);
extern void list_destroy(list_t **list, void (*)());
extern void *list_get_from_index(list_t *list, int index);
extern void *list_get_from_tag(list_t *list, char const *tag);
extern list_t *list_reverse(list_t *head);
extern void list_concat(list_t **dest, list_t *src);
extern void list_remove_from_index(list_t **list, int index, void (*)());
extern void list_remove_from_tag(list_t **list, char const *tag, void(*)());
extern int list_get_length(list_t *list);
extern void list_change_from_index(list_t *list, void *element, int index);
extern void list_change_from_tag(list_t *list, void *element, char const *tag);
extern void destroy_from_list(void *element, void (*element_destroy)());
extern bool list_exists(list_t *list, void *element);

#endif
