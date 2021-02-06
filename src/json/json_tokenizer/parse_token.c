/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

token_type_e get_token_type(char c)
{
    for (int i = 0; TOKENS[i] != '\0'; i++) {
        if (c == TOKENS[i])
            return LINK_TYPES[i].type;
    }
    return 0;
}

void valid_token(json_tokenizer_t *tokenizer, bool *got, int i)
{
    if (!is_num(TOKENS[i]) && TOKENS[i] != 't'
    && TOKENS[i] != 'f' && TOKENS[i] != 'n' && TOKENS[i] != '"') {
        tokenizer->token_length = 1;
        return;
    }
    if (TOKENS[i] == '"')
        parse_string_token(tokenizer);
    if (is_num(TOKENS[i]))
        parse_number_token(tokenizer);
    else {
        if (TOKENS[i] == 'n')
            parse_valid_token(tokenizer, got, "null");
        if (TOKENS[i] == 'f')
            parse_valid_token(tokenizer, got, "false");
        if (TOKENS[i] == 't')
            parse_valid_token(tokenizer, got, "true");
    }
}

void parse_token(json_tokenizer_t *tokenizer, int *status)
{
    int i = 0;
    bool got_token = false;

    skip_white_space(tokenizer);
    tokenizer->token_type = 0;
    tokenizer->token_length = 0;
    for (i = 0; TOKENS[i] != '\0'; i++)
        if (tokenizer->buffer->str[tokenizer->data_position] == TOKENS[i]) {
            got_token = true;
            break;
        }
    valid_token(tokenizer, &got_token, i);
    if (!got_token) {
        *status = EXEC_FAIL;
        return;
    }
    tokenizer->token_type =
    get_token_type(tokenizer->buffer->str[tokenizer->data_position]);
}
