NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= main.c \
			  main_init.c \
			  stack.c \
			  operations.c \
			  operations_exec.c \
			  utils.c \
			  utils_normalize.c \
			  find.c \
			  find_target.c \
			  move_cost.c \
			  move_find.c \
			  move_exec.c \
			  sort_three.c \
			  sort_turkish.c

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
