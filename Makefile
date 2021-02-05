##############################################
#			JSON PARSER LIB Makefile		 #
##############################################

CC					:=	gcc
CFLAGS				:= 	-Wall -Wextra -Werror -fpic

DEBUG_FLAGS			:=	-g3

VERSION				:=	1.0.0

RM					:=	rm -f

LIB_SRC				:=
LIB_OBJ				=	$(LIB_SRC:.c=.o)
LIB_NAME			:=	libc_json.so

UT_SRC				:=
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
tests_run:	$(UT_OBJ)

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
re: fclean all