/*
** PR0M3TH3USEX PROJECT, 2019
*/


#include "json_parser.h"

json_value_t *parse_null(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;

    if (tokenizer->token_type != J_NULL_TOKEN)
        return NULL;
    result = create_json_value(J_NULL);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    result->value.nothing = NULL;
    return result;
}