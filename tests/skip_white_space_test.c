/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(skip_white_space, no_spaces)
{
    char *str = "no_spaces";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    skip_white_space(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 0);
}

Test(skip_white_space, has_spaces)
{
    char *str = "   with_spaces";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    skip_white_space(&tokenizer);
    cr_assert_eq(tokenizer.data_position, 3);
}