/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** json_number_token.c
*/

#include "json_parser.h"

void parse_number_token(json_tokenizer_t *tokenizer)
{
    unsigned int tmp_pos = tokenizer->data_position;

    for (; is_num(tokenizer->buffer->str[tmp_pos]); tmp_pos++);
    tokenizer->token_length = tmp_pos - tokenizer->data_position;
}