##
## EPITECH PROJECT, 2023
## makefile lib
## File description:
## makefile
##

SRC =   sprite.c\
		sprite_2.c\
		sprite_3.c\
		spritesheets.c\
		spritesheets_2.c\
		animation.c\
		animation_2.c\
		map.c\
		map_layer.c\
		map_layer_2.c\
		button.c\

OBJ = $(SRC:.c=.o)

NAME = librpg.a

all: $(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
