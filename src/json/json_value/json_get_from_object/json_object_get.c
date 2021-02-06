/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_object_get_int.c
*/

#include "json_parser.h"

int json_object_get_int(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp || tmp->value_type != J_NUM)
        return J_ERROR_INT;
    return tmp->value.number;
}

bool json_object_get_bool(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp || tmp->value_type != J_BOOL)
        return J_ERROR_INT;
    return tmp->value.boolean;
}

char const *json_object_get_str(json_object_t *obj, char const *tag)
{
    json_value_t *tmp = L_TAG(obj, tag);

    if (!tmp || tmp->value_type != J_STR)
        return NULL;
    return tmp->value.string;
}