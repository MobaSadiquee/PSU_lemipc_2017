##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make for lemipc
##

NAME		= lemipc

SRC             = ./src/my_basic_func.c	\
		  ./src/check_func.c \
		  ./src/direction_func.c \
		  ./src/display_func.c \
		  ./src/champ_func.c \
		  ./src/init_func.c \
		  ./src/loop_func.c \
		  ./src/my_error_func.c \
		  ./src/state_func.c \
		  ./src/main.c

CC		= gcc

RM		= rm -rf

OBJ		= $(SRC:.c=.o)

CFLAGS		+= -I./include -I. -W -Wall -Wextra

all:
	@make --no-print-directory $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
