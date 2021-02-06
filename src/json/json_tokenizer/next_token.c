/*
** PR0M3TH3USEX PROJECT, 2019
*/

#include "json_parser.h"

void next_token(json_tokenizer_t *tokenizer)
{
    switch (tokenizer->token_type) {
        case J_STRING_TOKEN :
            tokenizer->data_position += tokenizer->token_length + 2;
            break;
        case J_CURLY_BRACKET_L:
        case J_CURLY_BRACKET_R:
        case J_SQUARE_BRACKET_L:
        case J_SQUARE_BRACKET_R:
        case J_COLON:
        case J_COMMA:
            tokenizer->data_position++;
            break;
        case J_NULL_TOKEN:
            tokenizer->data_position += 4;
            break;
        default:
            tokenizer->data_position += tokenizer->token_length;
    }
}