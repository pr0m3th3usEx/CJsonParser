/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void destroy_json_value(json_value_t *value)
{
    if (!value)
        return;
    if (value->value_type == J_OBJ)
        list_destroy(&value->value.obj, destroy_json_value);
    if (value->value_type == J_ARRAY) {
        for (int i = 0; i < value->value.array.length; i++)
            destroy_json_value(value->value.array.arr[i]);
        free(value->value.array.arr);
    }
    free(value);
}