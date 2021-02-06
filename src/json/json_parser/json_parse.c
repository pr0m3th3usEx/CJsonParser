/*
** PR0M3TH3USEX PROJECT, 2019
*/


#include "json_parser.h"

int json_parse(char const *str, json_value_t **obj)
{
    data_buffer_t buffer = {str, strlen(str)};
    json_tokenizer_t tokenizer = init_tokenizer(&buffer);
    int status = EXEC_SUCCESS;

    skip_white_space(&tokenizer);
    if (tokenizer.buffer->str[tokenizer.data_position] != '{'
    && tokenizer.buffer->str[tokenizer.data_position] != '[')
        return EXEC_FAIL;
    *obj = json_parse_value(&tokenizer, &status);
    if (status == EXEC_FAIL) {
        if (!(*obj))
            free(*obj);
        return EXEC_FAIL;
    }
    return EXEC_SUCCESS;
}

