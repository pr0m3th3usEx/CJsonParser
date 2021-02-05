/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_bool.c
*/

#include "json_parser.h"

json_value_t *parse_bool(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;

    if (tokenizer->token_type != J_BOOL_TOKEN)
        return NULL;
    result = create_json_value(J_BOOL);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    if (tokenizer->buffer->str[tokenizer->data_position] == 't')
        result->value.boolean = true;
    else
        result->value.boolean = false;
    return result;
}