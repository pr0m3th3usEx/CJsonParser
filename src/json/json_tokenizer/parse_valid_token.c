/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_bool_token.c
*/

#include "json_parser.h"

void parse_valid_token(json_tokenizer_t *tokenizer, bool *got, char const *test)
{
    if (strncmp(tokenizer->buffer->str + tokenizer->data_position,
    test, strlen(test)) != 0) {
        *got = false;
        return;
    }
    tokenizer->token_length = strlen(test);
}