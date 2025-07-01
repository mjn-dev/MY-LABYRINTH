##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Philibert Makefile
##

SRC_PATH = src/
UTILS_PATH = utils/
MOVEMENTS_PATH = movements/

SRC =	$(addprefix $(SRC_PATH), \
			$(addprefix $(UTILS_PATH), \
				my_putstr_err.c 	\
				print_debug.c		\
				free_queue.c		\
			) \
			$(addprefix $(MOVEMENTS_PATH), \
				bfs.c 			\
				execute_movements.c \
				neighbor_utils.c \
				path_utils.c \
				queue_utils.c \
			) \
			add_robot.c				\
			add_link.c				\
			add_room.c				\
			file_to_array.c			\
			parsing.c				\
			main.c					\
		) \

OBJ = $(SRC:.c=.o)

CC ?= gcc

CFLAGS = -Wall -Wextra

CPPFLAGS += -I./include

CRFLAGS = --coverage -lcriterion

LDFLAGS = -L lib

LDLIBS = -llinked-list -lmy

NAME = amazed

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) libs
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

debug: CFLAGS += -g3
debug: re

make_libmy:
	$(MAKE) -C lib/libmy

make_linked-list:
	$(MAKE) -C lib/linked-list

libs: make_libmy make_linked-list

clean:
		$(MAKE) clean -C lib/libmy
	$(MAKE) clean -C lib/linked-list
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
		$(MAKE) fclean -C lib/libmy
	$(MAKE) fclean -C lib/linked-list

re: fclean all

tests_run: CFLAGS += --coverage
tests_run: LDLIBS += -lcriterion
tests_run:
	$(CC) -o unit_tests $(SRC) tests/*.c $(CFLAGS) \
		$(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests

tests_cov:
	gcovr --exclude tests/
	gcovr --exclude tests/ --txt-metric branch
	$(RM) *unit*

fcheck:
	bash assets/bash_script/banned_function_checker.sh .

.PHONY: all libs clean fclean re tests_run tests_cov fcheck \
    libs make_libmy make_linked-list debug
