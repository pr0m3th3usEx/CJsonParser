/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

json_tokenizer_t init_tokenizer(data_buffer_t *buffer)
{
    json_tokenizer_t tokenizer = {buffer, 0, 0, 0};

    return tokenizer;
}
