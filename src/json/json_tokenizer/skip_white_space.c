/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** skip_white_space.c
*/

#include "json_parser.h"

void skip_white_space(json_tokenizer_t *tokenizer)
{
    bool is_white_space = true;

    while (is_white_space) {
        switch (tokenizer->buffer->str[tokenizer->data_position]) {
            case ' ':
            case '\r':
            case '\t':
            case '\n':
                tokenizer->data_position++;
                break;
            default:
                is_white_space = false;
        }
    }
}