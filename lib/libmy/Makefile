##
## EPITECH PROJECT, 2025
## makefile
## File description:
## just a makefile
##

SRC =   my_getnbr.c	\
		my_getnbr_parsing.c \
		my_putchar.c \
        my_put_nbr.c \
        my_putstr.c \
		my_put_double.c \
        my_strcat.c \
        my_strcmp.c \
        my_strcpy.c \
        my_strdup.c \
        my_strlen.c \
        my_strncat.c \
        my_strncmp.c \
        my_strncpy.c \
        my_strstr.c \
        my_swap.c \
		handle_scient.c \
		handle_ptr.c \
		handle_n.c \
		handle_float.c \
		handle_char.c \
		handle_int.c \
		handle_str.c \
		handle_percent.c \
		handle_hex.c \
		handle_min_hex.c \
		handle_oct.c \
		handle_u.c \
		my_put_scient.c \
		print_long.c \
		convert_base.c \
		my_return.c \
		my_revstr.c \
		my_strchr.c \
		my_strtok.c \
		my_putnbr_base.c \
		my_strcspn.c \
		my_printf.c \
		callback_int.c \
		my_str_to_word_array.c \
		free_and_null.c \
		my_realloc.c \
		my_memcpy.c \
		my_memset.c \
		my_calloc.c \

OBJ = $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	mkdir -p ../../include/
	cp includes/my.h ../../include/
	cp includes/flag.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
re:
	fclean all
