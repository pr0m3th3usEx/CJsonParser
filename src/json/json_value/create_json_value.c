/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

json_value_t *create_json_value(json_type_e type)
{
    json_value_t *value = malloc(sizeof(*value));

    CHECK_MALLOC(value)
    value->value_type = type;
    value->value.number = 0;
    value->value.obj = NULL;
    value->value.boolean = false;
    value->value.nothing = NULL;
    memset(value->value.string, '\0', 255);
    return value;
}
