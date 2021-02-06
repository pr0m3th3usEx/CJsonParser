/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(next_token, one_step)
{
    char *str = "{ \"test\" : 2 }";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    tokenizer.token_type = J_CURLY_BRACKET_L;
    next_token(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 1);
}

Test(next_token, str_offset)
{
    char *str = "{ \"test\' : 2 }";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    tokenizer.token_type = J_STRING_TOKEN;
    tokenizer.data_position = 2;
    tokenizer.token_length = 5;
    next_token(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 9);
}

Test(next_token, null)
{
    char *str = "{ \"test\' : 2 }";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    tokenizer.token_type = J_NULL_TOKEN;
    tokenizer.data_position = 0;
    next_token(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 4);
}

Test(next_token, other)
{

    char *str = "{ \"test\' : 2 }";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    tokenizer.token_type = J_NUMBER_TOKEN;
    tokenizer.data_position = 0;
    tokenizer.token_length = 3;
    next_token(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 3);
}