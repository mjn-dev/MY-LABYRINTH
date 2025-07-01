##
## EPITECH PROJECT, 2025
## makefile
## File description:
## just a makefile
##

SRC =   create_node.c \
		insert_at_beginning.c \
		insert_at_end.c \
		delete_node.c \
		print_list.c \
		free_list.c \
		search.c \
		insert_after.c \
		get_length.c \
		insert_at_position.c \
		reverse_list.c \
		auto_free.c \

OBJ = $(SRC:.c=.o)

NAME = liblinked-list.a

CFLAGS = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o
	cp $(NAME) ../
	mkdir -p ../../include/
	cp includes/linked_list.h ../../include/

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
re:
	fclean all
