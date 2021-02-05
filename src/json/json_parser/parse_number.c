/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_number.c
*/

#include "json_parser.h"

json_value_t *parse_number(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;

    if (tokenizer->token_type != J_NUMBER_TOKEN)
        return NULL;
    result = create_json_value(J_NUM);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    result->value.number = atoi(tokenizer->buffer->str + tokenizer->data_position);
    return result;
}