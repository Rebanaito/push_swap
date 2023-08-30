UNAME_S := $(shell uname -s)
NAME	=	push_swap
SRC		=	src/input.c src/push_pop.c src/swap.c src/utils_2.c\
			src/rotate.c src/rrotate.c src/short_sort.c src/long_sort.c src/utils.c\
			src/long_utils.c src/long_utils_2.c src/long_utils_3.c src/move_stacks.c\
			src/short_utils.c src/short_utils_2.c
LIBFT	=	./includes/libft
OBJ		=	${SRC:.c=.o}
LIBC	=	ar	-rc
CC		=	cc
RM		=	rm -rf
CFLAGS	=	-Wall -Wextra -Werror 

all : ${LIBFT} ${NAME}

${NAME} : ${LIBFT} ${SRC}
		cp includes/libft/libft.a .
		${CC} ${CFLAGS} ${SRC} src/main.c libft.a -o ${NAME}

${LIBFT}:
		${MAKE} -C $@

clean :
		${MAKE} clean -C ${LIBFT}

fclean : clean
		${RM} ${NAME} ./checker
		${RM} libft.a
		${MAKE} fclean -C ${LIBFT}

bonus: ${LIBFT} ${SRC}
		cp includes/libft/libft.a .
		${CC} ${CFLAGS} ${SRC} src/bonus.c libft.a -o checker
		
re :	fclean all

.PHONY: all clean fclean re ${LIBFT}