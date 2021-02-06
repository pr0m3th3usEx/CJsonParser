/*
** PR0M3TH3USEX PROJECT, 2019
*/


#include "json_parser.h"

void get_next_token(json_tokenizer_t *tokenizer, int *status)
{
    next_token(tokenizer);
    parse_token(tokenizer, status);
}

void load_object(json_tokenizer_t *tokenizer, int *status, json_value_t *result)
{
    char key[255] = {0};
    json_value_t *tmp = NULL;

    while (tokenizer->token_type != J_CURLY_BRACKET_R) {
        CHECK_FAIL(*status)
        get_key(tokenizer, key);
        get_next_token(tokenizer, status);
        next_token(tokenizer);
        tmp = json_parse_value(tokenizer, status);
        CHECK_FAIL(*status)
        list_push(&result->value.obj, tmp, key);
        get_next_token(tokenizer, status);
        if (tokenizer->token_type == J_COMMA)
            get_next_token(tokenizer, status);
    }
}

json_value_t *parse_object(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;

    if (tokenizer->token_type != J_CURLY_BRACKET_L)
        return NULL;
    result = create_json_value(J_OBJ);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    get_next_token(tokenizer, status);
    load_object(tokenizer, status, result);
    return result;
}