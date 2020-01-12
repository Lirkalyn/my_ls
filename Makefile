##
## EPITECH PROJECT, 2019
## Day_10
## File description:
## makefile
##
.PHONY : clean fclean re

SRC	=	main.c \
		l_1.c \
		l_1_2.c \
		file.c \
		general.c \
		display.c \
		display_2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
