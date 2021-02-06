/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_array_get.c
*/

#include "json_parser.h"

int json_array_get_int(json_array_t *array, int index)
{
    if (index < 0 || index >= array->length)
        return J_ERROR_INT;
    return get_int_value(array->arr[index]);
}

char const *json_array_get_str(json_array_t *array, int index)
{
    if (index < 0 || index >= array->length)
        return NULL;
    return get_string_value(array->arr[index]);
}

bool json_array_get_bool(json_array_t *array, int index)
{
    if (index < 0 || index >= array->length)
        return NULL;
    return get_bool_value(array->arr[index]);
}

json_object_t *json_array_get_object(json_array_t *array, int index)
{
    if (index < 0 || index >= array->length)
        return NULL;
    return get_json_object(array->arr[index]);
}