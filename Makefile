##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

MAIN	=		src/main.c

SRC		=		src/get_word.c		\
				src/get_info.c 		\
				src/ai.c			\
				src/action.c		\
				src/get_stat_info.c

OBJ		=		$(SRC:.c=.o) $(MAIN:.c=.o)

TESTS	=

NAME	=		ai

LIB		=		lib/libmy.a

CFLAGS 		=	-W -Wall -Wextra -g

CPPFLAGS	=	-I./include

LDFLAGS	=	-Llib/

LDIBS	=	-lmy

all:		$(NAME)

$(NAME):	$(OBJ) $(LIB)
			cp n4s_package/n4s .
			cp n4s_package/n4s_buffer .
			cp n4s_package/pipes.sh .
			gcc -o $(NAME) $(OBJ) $(CPPFLAGS)

$(LIB):
			make -s -C lib/my

run:		$(NAME)
			./n4s_package/pipes.sh

tests_run:	LDIBS += -lcriterion --coverage
tests_run:	all
			gcc -o $@ $(SRC) $(TESTS) $(CPPFLAGS) $(LDIBS)
			-./$@

clean:
		$(RM) -f src/*.o
		$(RM) *~
		$(RM) *.gc*

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(LIB)
		$(RM) n4s
		$(RM) n4s_buffer
		$(RM) pipes.sh
		$(RM) tests_run
		make -s -C lib/my fclean

re:		fclean all

.PHONY: re fclean clean tests_run all
