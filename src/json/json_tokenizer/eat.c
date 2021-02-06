/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"
#include <math.h>

int eat_comma(json_tokenizer_t *tokenizer)
{
    if (tokenizer->buffer->str[tokenizer->data_position] != ',')
        return EXEC_FAIL;
    tokenizer->data_position++;
    return EXEC_SUCCESS;
}

int eat_colon(json_tokenizer_t *tokenizer)
{
    if (tokenizer->buffer->str[tokenizer->data_position] != ':')
        return EXEC_FAIL;
    tokenizer->data_position++;
    return EXEC_SUCCESS;
}