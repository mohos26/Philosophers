SRCS = aid/ft_atio.c aid/ft_isdigit.c aid/ft_putendl_fd.c aid/ft_putchar_fd.c aid/ft_putstr_fd.c \
src/ft_get_args.c src/ft_get_info.c src/ft_get_time.c src/ft_monitor.c src/ft_philos.c \
src/ft_start.c src/main.c src/ft_finsh_check.c src/ft_died_check.c

OBJS = ${SRCS:.c=.o}

NAME = philo

%.o: %.c header.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
	cc $^ -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
