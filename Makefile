NAME = libftprintf.a
CCFLAGS = -Wall -Wextra -Werror
CC = cc
INCLUDE = -I ./
AR = ar -rcs
RM = rm -f

SRCS = ft_printf.c 		  \
		ft_printfUtils.c  \

OBJS := ${SRCS:.c=.o}

%.o: %.c
	${CC} ${CCFLAGS} ${INCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

clean: 
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
