##
## EPITECH PROJECT, 2023
## makefile lib
## File description:
## makefile
##

SRC =   free.c\
	my_memset.c\
	is_mt.c\
	space_fix.c\
	my_sort_word_array.c\
	my_show_word_array.c\
	my_put_unsigned.c\
	my_putfloat.c\
	my_putfloat_base.c\
	my_put_exposant.c\
	my_put_exposant_base.c\
	my_nb_to_string_base.c\
	my_put_no_trail.c\
	my_printf.c\
	printf_error.c\
	flags_mini.c\
	flags_int.c\
	flags_base.c\
	flags_precise.c\
	flags_special.c\
	flags_absolute.c\
	my_append.c\
	my_compute_power_rec.c\
	my_compute_square_root.c\
	my_find_prime_sup.c\
	my_getnbr_base.c\
	my_getnbr.c\
	my_isneg.c\
	my_is_prime.c\
	my_len.c\
	my_putchar.c\
	my_putnbr_base.c\
	my_put_nbr.c\
	my_putstr.c\
	my_revstr.c\
	my_showmem.c\
	my_showstr.c\
	my_sort_int_array.c\
	my_strcapitalize.c\
	my_strcat.c\
	my_strcmp.c\
	my_strcpy.c\
	my_strdup.c\
	my_str_isalpha.c\
	my_str_islower.c\
	my_str_isnum.c\
	my_str_isprintable.c\
	my_str_isupper.c\
	my_strlen.c\
	my_strlowcase.c\
	my_strncat.c\
	my_strncmp.c\
	my_strncpy.c\
	my_strstr.c\
	my_strtok.c\
	my_str_to_word_array.c\
	my_strupcase.c\
	my_swap.c\
	ptr_swap.c\
	constant.c\
	my_put_flaga.c\
	get_file_content.c\
	my_realloc.c\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
