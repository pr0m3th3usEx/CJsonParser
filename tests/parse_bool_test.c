/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_bool_test.c
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_bool, valid_false)
{
    char *str = "false";
    int status = 0;
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;

    parse_token(&tokenizer, &status);
    value = parse_bool(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_BOOL);
    cr_assert_eq(value->value.boolean, false);
    destroy_json_value(value);
}

Test(parse_bool, valid_true)
{
    char *str = "true";
    int status = 0;
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;
    parse_token(&tokenizer, &status);
    value = parse_bool(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_BOOL);
    cr_assert_eq(value->value.boolean, true);
    destroy_json_value(value);
}