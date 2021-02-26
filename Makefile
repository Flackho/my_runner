##
## EPITECH PROJECT, 2020
## delivery
## File description:
## Makefile
##

.PHONY =	clean fclean re

SRC =	src/my_display.c	\
		functions/my_putstr.c 	\
		src/my_character.c 	\
		src/movement.c 	\
		src/my_menu.c 	\
		src/main.c 	\
		src/my_help.c 	\
		src/my_texture.c 	\
		src/my_music.c 	\
		src/my_update.c 	\
		src/my_score.c 	\
		src/load_file_mem.c 	\
		src/my_enemy.c 	\
		src/my_win.c \

OBJ = $(SRC:.c=.o)

NAME = my_runner

CFLAGS	+=	-I./include -g3 -lm

CSFML	= -l csfml-graphics -l csfml-system -l csfml-audio -l csfml-network -l csfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFML)
		rm -f src/*.o functions/*.o main.o
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all