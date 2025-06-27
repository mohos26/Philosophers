/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:29:40 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/27 09:31:34 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_all
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_philo_must_eat;
	pthread_mutex_t	*forks;
	long			last_meal[200];
	int				is_eating[200];
	pthread_mutex_t	meal_mutex;
	pthread_t		*philos;
	pthread_t		*monitor;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	print_mutex;
	int				finish;
	int				died_flag;
}					t_all;

// ------------ aid ------------
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(char *s);
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
// ------------ src ------------
t_all	*ft_get_info(char **av);
t_all	*ft_get_arg(t_all *arg);
long	ft_get_time(void);
long	ft_start(int flag);
void	*ft_philos(void *n);
void	*ft_monitor(void *data);
int		ft_finsh_check(t_all *arg);
int		ft_died_check(t_all *arg);

#endif
