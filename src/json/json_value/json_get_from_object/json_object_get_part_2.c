/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_object_get_part_2.c
*/

#include "json_parser.h"

json_object_t *json_object_get_object(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp || tmp->value_type != J_OBJ)
        return NULL;
    return tmp->value.obj;
}

void *json_object_get_null(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp || tmp->value_type != J_NULL)
        return NULL;
    return tmp->value.nothing;
}

json_array_t json_object_get_array(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp)
        return (json_array_t) {NULL, -1, 84};
    return tmp->value.array;
}