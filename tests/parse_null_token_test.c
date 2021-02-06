/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_valid_token, valid_null_token)
{
    char *str = "null";
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "null");
    cr_assert_eq(got_token, true);
    cr_assert_eq(tokenizer.token_length, 4);
}

Test(parse_valid_token, invalid_null_token)
{
    char *str = "nlse";
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    bool got_token = true;

    parse_valid_token(&tokenizer, &got_token, "null");
    cr_assert_eq(got_token, false);
    cr_assert_eq(tokenizer.token_length, 0);
}
