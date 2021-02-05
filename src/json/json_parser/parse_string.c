/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_string.c
*/

#include "json_parser.h"

char *get_key(json_tokenizer_t *tokenizer, char *key)
{
    unsigned int i = 0;

    memset(key, '\0', 255);
    if (tokenizer->token_type != J_STRING_TOKEN)
        return NULL;
    for (i = 1; i <= tokenizer->token_length; i++)
        key[i - 1] = tokenizer->buffer->str[i + tokenizer->data_position];
    return key;
}

json_value_t *parse_string(json_tokenizer_t *tokenizer, int *status)
{
    unsigned int i = 0;
    json_value_t *result = NULL;

    if (tokenizer->token_type != J_STRING_TOKEN)
        return NULL;
    result = create_json_value(J_STR);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    for (i = 1; i <= tokenizer->token_length; i++)
        result->value.string[i - 1] =
        tokenizer->buffer->str[i + tokenizer->data_position];
    return result;
}