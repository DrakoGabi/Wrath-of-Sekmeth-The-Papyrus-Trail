##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile_rpg
##

SRC =   main.c\
		menu.c\
		create.c\
		place_fight.c\
		test_setup.c\
		base_stats.c\
		just_pressed.c\
		menu_2.c\
		player_input_fight.c\
		overworld.c\
		text_catcher.c\
		fight_window.c\
		fight.c\
		entities.c\
		view.c\
		mouvement.c\
		launch_fight.c\
		level_up.c\
		activate_boss.c\
		check_entry.c\
		npc.c\
		npc_2.c\
		get_inventory.c\
		my_strnb_cpy.c\
		victory_state.c\
		flip.c\
		music_manager.c\
		settings.c\
		menu_pause.c\
		generic.c\
		menu_pause_2.c\
		menu_pause_3.c\
		inv_button.c\
		memory_cutscene.c\
		cutscene.c\
		change_inv_state.c\
		controls.c\
		link.c\
		save.c\
		save_in_menu.c\

OBJ = $(SRC:.c=.o)

NAME = my_rpg

CFLAGS = -W -Wall -Wextra -Werror -lcsfml-graphics -lcsfml-window -L \
	     lib/my/ -lmy -I include/ -lcsfml-system -lcsfml-audio -lm \
		 -L engine/ -lrpg

all: $(OBJ)
	make -C lib/my/
	make -C engine/
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)
	make -C lib/my/ clean
	make -C engine/ clean

fclean: clean
	rm -rf $(NAME)
	make -C lib/my/ fclean
	make -C engine/ fclean

re: fclean all
