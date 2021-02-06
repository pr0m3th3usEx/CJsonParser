/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void parse_string_token(json_tokenizer_t *tokenizer)
{
    unsigned int tmp_pos = tokenizer->data_position;
    bool end_of_string = false;

    while (!end_of_string) {
        tmp_pos++;
        if (tokenizer->buffer->str[tmp_pos] ==  '"')
            end_of_string = (tokenizer->buffer->str[tmp_pos - 1] != '\\')
            ? true
            : false;
    }
    tokenizer->token_length = tmp_pos - tokenizer->data_position - 1;
}