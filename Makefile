SRC =		main.c \
			process.c \
			end_process.c \
			handle_args.c

LIBFT = 	libft/libft.a

NAME = 		pipex
FLAGS =		-Wall -Wextra -Werror

OBJS = ${SRC:%.c=%.o}

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	cc -g ${FLAGS} ${OBJS} ${LIBFT} -o $@

%.o: %.c
	cc -g -c ${FLAGS} $< -o $@

${LIBFT}:
	make -sC libft/

clean: 
	rm -f ${OBJS}
	make clean -sC libft/

fclean: clean
	rm -rf ${NAME}
	rm -f ${OBJS}
	make fclean -sC libft/

re: fclean all

PHONY: all clean fclean re