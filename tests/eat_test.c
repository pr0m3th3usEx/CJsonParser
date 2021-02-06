/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(eat_comma, no_comma)
{
    char *str = " jddf,";
    data_buffer_t data_buffer =  {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    cr_assert_eq(eat_comma(&tokenizer), EXEC_FAIL);
    cr_assert_eq(tokenizer.data_position, 0);
}

Test(eat_comma, with_comma)
{
    char *str = ", mlv";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    cr_assert_eq(eat_comma(&tokenizer), EXEC_SUCCESS);
    cr_assert_eq(tokenizer.data_position, 1);
}

Test(eat_colon, no_colon)
{
    char *str = " jddf:";
    data_buffer_t data_buffer =  {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    cr_assert_eq(eat_colon(&tokenizer), EXEC_FAIL);
    cr_assert_eq(tokenizer.data_position, 0);
}

Test(eat_colon, with_colon)
{
    char *str = ": mlv";
    data_buffer_t data_buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&data_buffer);

    cr_assert_eq(eat_colon(&tokenizer), EXEC_SUCCESS);
    cr_assert_eq(tokenizer.data_position, 1);
}