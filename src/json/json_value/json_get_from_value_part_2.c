/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void *get_null_value(json_value_t *v)
{
    return v->value.nothing;
}

bool get_bool_value(json_value_t *v)
{
    if (v->value_type != J_BOOL)
        return J_ERROR_INT;
    return v->value.boolean;
}

char const *get_string_value(json_value_t *v)
{
    if (v->value_type != J_STR)
        return NULL;
    return v->value.string;
}