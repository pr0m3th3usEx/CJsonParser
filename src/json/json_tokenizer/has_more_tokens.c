/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** has_more_tokens.c
*/

#include "json_parser.h"

bool has_more_tokens(json_tokenizer_t *tokenizer)
{
    return tokenizer->data_position + tokenizer->token_length <
    tokenizer->buffer->length;
}