SRCS = ft_strlen.c ft_calloc.c ft_strdup.c \
       ft_strncmp.c ft_substr.c ft_strjoin.c ft_split.c \
       ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \

OBJS = ${SRCS:.c=.o}
NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -fPIC

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all bonus clean fclean re
