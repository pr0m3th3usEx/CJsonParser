/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_string, valid_string)
{
    char *str = "\"test\"";
    int status = 0;
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;

    parse_token(&tokenizer, &status);
    value = parse_string(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_STR);
    cr_assert_str_eq(value->value.string, "test");
    destroy_json_value(value);
}