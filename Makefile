NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes
RM			= rm -f

SRCS		= src/main.c \
			  src/main_init.c \
			  src/stack.c \
			  src/operations.c \
			  src/operations_exec.c \
			  src/utils.c \
			  src/utils_normalize.c \
			  src/find.c \
			  src/find_target.c \
			  src/move_cost.c \
			  src/move_find.c \
			  src/move_exec.c \
			  src/sort_three.c \
			  src/sort_turkish.c

OBJS		= $(SRCS:.c=.o)

HEADER		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
