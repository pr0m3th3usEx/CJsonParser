/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

bool has_more_tokens(json_tokenizer_t *tokenizer)
{
    return  tokenizer->data_position + tokenizer->token_length <
            tokenizer->buffer->length;
}