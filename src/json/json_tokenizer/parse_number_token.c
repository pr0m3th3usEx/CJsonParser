/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void parse_number_token(json_tokenizer_t *tokenizer)
{
    unsigned int tmp_pos = tokenizer->data_position;

    for (; is_num(tokenizer->buffer->str[tmp_pos]); tmp_pos++);
    tokenizer->token_length = tmp_pos - tokenizer->data_position;
}