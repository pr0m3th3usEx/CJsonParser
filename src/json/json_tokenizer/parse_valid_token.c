/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void parse_valid_token(json_tokenizer_t *tokenizer, bool *got, char const *test)
{
    if (strncmp(tokenizer->buffer->str + tokenizer->data_position,
    test, strlen(test)) != 0) {
        *got = false;
        return;
    }
    tokenizer->token_length = strlen(test);
}