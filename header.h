/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:29:25 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/21 16:19:14 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <libc.h>
# include <pthread.h>

typedef struct s_philosophers
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_philosophers;

/* aid files*/
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putstr_fd(char *s, int fd);
void			*ft_malloc(size_t size);
void			ft_exit(int status);
int				ft_isdigit(int c);

/* src */
int				ft_get_info(char **av, int i);
int				ft_atoi(char *s);
pthread_mutex_t	*ft_forks(int i);
void			*ft_philosopher(void *n);
long			ft_get_time(void);

#endif
