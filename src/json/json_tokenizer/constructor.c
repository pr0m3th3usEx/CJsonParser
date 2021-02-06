/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** constructor.c
*/

#include "json_parser.h"

json_tokenizer_t init_tokenizer(data_buffer_t *buffer)
{
    json_tokenizer_t tokenizer = {buffer, 0, 0, 0};

    return tokenizer;
}
