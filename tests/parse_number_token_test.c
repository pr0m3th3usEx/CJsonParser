/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_number_token, test)
{
    char *str = "03456";
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);

    parse_number_token(&tokenizer);
    cr_assert_eq(tokenizer.token_length, 5);
}