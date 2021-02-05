##############################################
#			JSON PARSER LIB Makefile		 #
##############################################

CC					:=	gcc
CFLAGS				:= 	-Wall -Wextra -Werror -fpic
CPPFLAGS			:=	-I./include

DEBUG_FLAGS			:=	-g3

VERSION				:=	1.0.0

RM					:=	rm -f

LIB_SRC				:= 	src/list/list_change.c												\
						src/list/list_concat.c												\
						src/list/list_destroy.c												\
						src/list/list_exists.c												\
						src/list/list_get_length.c											\
						src/list/list_get.c													\
						src/list/list_push.c												\
						src/list/list_remove.c												\
						src/list/list_reverse.c												\
						src/json/json_parser/json_parse_value.c								\
						src/json/json_parser/json_parse.c									\
						src/json/json_parser/parse_array.c									\
						src/json/json_parser/parse_bool.c									\
						src/json/json_parser/parse_null.c									\
						src/json/json_parser/parse_number.c									\
						src/json/json_parser/parse_object.c									\
						src/json/json_parser/parse_string.c									\
						src/json/json_tokenizer/constructor.c								\
						src/json/json_tokenizer/eat.c										\
						src/json/json_tokenizer/has_more_tokens.c							\
						src/json/json_tokenizer/next_token.c								\
						src/json/json_tokenizer/parse_number_token.c						\
						src/json/json_tokenizer/parse_string_token.c						\
						src/json/json_tokenizer/parse_token.c								\
						src/json/json_tokenizer/parse_valid_token.c							\
						src/json/json_tokenizer/skip_white_space.c							\
						src/json/json_value/create_json_value.c								\
						src/json/json_value/destroy_json_value.c							\
						src/json/json_value/get_json_from_file.c							\
						src/json/json_value/json_get_from_value_part_2.c					\
						src/json/json_value/json_get_from_value.c							\
						src/json/json_value/json_get_from_array/json_array_get.c			\
						src/json/json_value/json_get_from_object/json_object_get.c			\
						src/json/json_value/json_get_from_object/json_object_get_part_2.c

LIB_OBJ				=	$(LIB_SRC:.c=.o)
LIB_NAME			:=	libc_json.so

UT_SRC				:=	tests/eat_test.c													\
						tests/next_token_test.c												\
						tests/parse_bool_test.c												\
						tests/parse_null_test.c												\
						tests/parse_null_token_test.c										\
						tests/parse_number_token_test.c										\
						tests/parse_object_test.c											\
						tests/parse_string_test.c											\
						tests/parse_string_token_test.c										\
						tests/parse_valid_token_test.c										\
						tests/skip_white_space_test.c

UT_OBJ				=	$(UT_SRC:.c=.o)
UT_NAME				:=	unit_tests


.PHONY	=	all
all:
	@echo "###########################################"
	@echo "  C JSON PARSER v$(VERSION) - by Pr0m3th3usEx"
	@echo "###########################################"
	@echo ""
	@echo 'Use "make install" the library and header files'

.PHONY	=	install
install:
	@echo "[+] Criterion dependency"
	@./install_criterion.sh
	@echo "[+] Gcovr dependency"
	@apt install gcovr

.PHONY	=	tests_run
tests_run:	CFLAGS	+=	--coverage
tests_run:	LDFLAGS	+=	-lcriterion
tests_run:	$(UT_OBJ) $(LIB_OBJ)
	@gcc $(CPPFLAGS) $(CFLAGS) -o $(UT_NAME) $(UT_OBJ) $(LIB_OBJ) $(LDFLAGS)
	@./$(UT_NAME)

.PHONY	=	coverage
coverage:
	gcovr -r . --exclude tests/
	gcovr -r . --exclude tests/ --branches

.PHONY	=	clean
clean:	$(LIB_OBJ)
	$(RM) $(LIB_OBJ)

.PHONY	=	fclean
fclean: clean
	@$(RM) $(LIB_NAME)
	@$(RM) $(UT_NAME)
	@find . -name "*.gcno" -delete -o -name "*.gcda" -delete

.PHONY	=	re
re: fclean install