SRCS = aid/ft_atoi.c aid/ft_isdigit.c aid/ft_putchar_fd.c aid/ft_putendl_fd.c aid/ft_putstr_fd.c \
aid/ft_strlen.c src/ft_forks.c src/ft_get_info.c src/ft_get_time.c src/ft_philosopher.c \
src/ft_start_time.c src/main.c src/ft_monitor.c

OBJS = ${SRCS:.c=.o}

NAME = philo

%.o: %.c header.h
		cc -Wall -Werror -Wextra -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
		cc $^ -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
