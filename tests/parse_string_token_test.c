/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_string_token.c
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_string_token, no_instr_quote)
{
    char *str = "\"false\"";
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);

    parse_string_token(&tokenizer);
    cr_assert_eq(tokenizer.token_length, 5);
}