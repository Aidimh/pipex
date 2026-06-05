NAME    = pipex
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LIBFT   = ./libft/libft.a
SRCS    = ./src/pipex.c ./src/utils.c ./src/checks.c
OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./libft -I ./src -c $< -o $@

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
