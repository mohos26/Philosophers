/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:29:40 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 09:02:33 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H
# include <libc.h>
# include <pthread.h>

typedef struct s_all
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				number_philo_must_eat;
	pthread_mutex_t	*forks;
	long			last_meal[200];
	pthread_mutex_t	meal_mutex;
	pthread_t		*philos;
	pthread_t		*monitor;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	print_mutex;
	int				finish;
	int				died_flag;
}					t_all;

int		ft_atoi(char *s);
t_all	*ft_get_info(char **av);
void	ft_putstr_fd(char *s, int fd);
t_all	*ft_get_arg(t_all *arg);
long	ft_get_time(void);
long	ft_start(int flag);
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
void	*ft_philos(void *n);
void	ft_putchar_fd(char c, int fd);
void	*ft_monitor(void *data);
int		ft_finsh_check(t_all *arg);
int		ft_died_check(t_all *arg);
#endif
