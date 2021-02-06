/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <criterion/criterion.h>

Test(parse_number, valid_number)
{
    char *str = "{ \"mlv\" : 3}";
    int status = 0;
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    json_value_t *value = NULL;

    parse_token(&tokenizer, &status);
    value = parse_object(&tokenizer, &status);
    cr_assert_eq(value->value_type, J_OBJ);
    cr_assert_not_null(value->value.obj);
    cr_assert_eq(((json_value_t *)
    L_TAG(value->value.obj, "mlv"))->value.number, 3);
    destroy_json_value(value);
}