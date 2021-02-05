/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_parse_value.c
*/

#include "json_parser.h"

json_value_t *json_parse_value_next(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;
    result = parse_null(tokenizer, status);
    CHECK_CORRUPTED(*status)
    if (result)
        return result;
    result = parse_bool(tokenizer, status);
    if (result)
        return result;
    result = parse_array(tokenizer, status);
    CHECK_CORRUPTED(*status)
    return result;
}

json_value_t *json_parse_value(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;

    parse_token(tokenizer, status);
    result = parse_object(tokenizer, status);
    CHECK_CORRUPTED(*status)
    if (result)
        return result;
    result = parse_string(tokenizer, status);
    CHECK_CORRUPTED(*status)
    if (result)
        return result;
    result = parse_number(tokenizer, status);
    CHECK_CORRUPTED(*status)
    if (result)
        return result;
    return json_parse_value_next(tokenizer, status);
}