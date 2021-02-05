/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** parse_array.c
*/

#include "json_parser.h"

json_value_t *transform_list_to_array(json_value_t *result, list_t *ele,
json_type_e type_data, int *status)
{
    list_t *tmp = ele;

    CHECK_CORRUPTED(*status)
    result->value.array.length = list_get_length(ele);
    result->value.array.type = type_data;
    result->value.array.arr = malloc(sizeof(json_value_t) *
    (result->value.array.length + 1));
    CHECK_MALLOC(result->value.array.arr);
    for (int i = 0; i < result->value.array.length; i++) {
        result->value.array.arr[i] = ele->element;
        ele = ele->next;
    }
    result->value.array.arr[result->value.array.length] = NULL;
    list_destroy(&tmp, NULL);
    return result;
}

void load_array(json_tokenizer_t *tokenizer, int *status, json_type_e *type,
list_t **tmp)
{
    json_value_t *element = NULL;
    bool initial = true;

    while (tokenizer->token_type != J_SQUARE_BRACKET_R) {
        element = json_parse_value(tokenizer, status);
        CHECK_FAIL(*status)
        if (initial) {
            *type = element->value_type;
            initial = false;
        }
        list_push(tmp, element, NULL);
        get_next_token(tokenizer, status);
        if (tokenizer->token_type == J_COMMA)
            get_next_token(tokenizer, status);
    }
}

json_value_t *parse_array(json_tokenizer_t *tokenizer, int *status)
{
    json_value_t *result = NULL;
    json_type_e type;
    list_t *tmp = NULL;

    if (tokenizer->token_type != J_SQUARE_BRACKET_L)
        return NULL;
    result = create_json_value(J_ARRAY);
    if (!result) {
        *status = EXEC_FAIL;
        return NULL;
    }
    get_next_token(tokenizer, status);
    load_array(tokenizer, status, &type, &tmp);
    tmp = list_reverse(tmp);
    return transform_list_to_array(result, tmp, type, status);
}