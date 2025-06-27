/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:53:01 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/26 10:55:04 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_take_fork(t_all *arg, int fork_id, long start, int id)
{
	pthread_mutex_lock(&arg->forks[fork_id]);
	if (ft_died_check(arg))
	{
		pthread_mutex_lock(&arg->print_mutex);
		printf("%ld %d has taken a fork\n", ft_get_time() - start, id);
		pthread_mutex_unlock(&arg->print_mutex);
	}
}

static void	ft_eating(t_all *arg, long start, int id)
{
	int	left;
	int	rigth;

	left = id - 1;
	rigth = id % arg->number_philo;
	ft_take_fork(arg, rigth, start, id);
	ft_take_fork(arg, left, start, id);
	if (ft_died_check(arg))
	{
		pthread_mutex_lock(&arg->print_mutex);
		printf("%ld %d is eating\n", ft_get_time() - start, id);
		pthread_mutex_unlock(&arg->print_mutex);
	}
	pthread_mutex_lock(&arg->meal_mutex);
	arg->is_eating[id -1] = 1;
	arg->last_meal[id -1] = ft_get_time();
	pthread_mutex_unlock(&arg->meal_mutex);
	usleep(arg->time_eat * 1000);
	pthread_mutex_lock(&arg->meal_mutex);
	arg->is_eating[id -1] = 0;
	pthread_mutex_unlock(&arg->meal_mutex);
	pthread_mutex_unlock(&arg->forks[left]);
	pthread_mutex_unlock(&arg->forks[rigth]);
}

static void	ft_sleeping(t_all *arg, long start, int id)
{
	if (ft_died_check(arg))
	{
		pthread_mutex_lock(&arg->print_mutex);
		printf("%ld %d is sleeping\n", ft_get_time() - start, id);
		pthread_mutex_unlock(&arg->print_mutex);
	}
	usleep(arg->time_sleep * 1000);
}

static void	ft_thinking(t_all *arg, long start, int id)
{
	if (ft_died_check(arg))
	{
		pthread_mutex_lock(&arg->print_mutex);
		printf("%ld %d is thinking\n", ft_get_time() - start, id);
		pthread_mutex_unlock(&arg->print_mutex);
	}
}

void	*ft_philos(void *n)
{
	long	start;
	t_all	*arg;
	int		id;
	int		i;

	arg = ft_get_arg(NULL);
	id = *(int *)n + 1;
	arg->is_eating[id - 1] = 0;
	i = 0;
	start = ft_start(1);
	if (!(id % 2))
		usleep(1000);
	while (i++ != arg->number_philo_must_eat)
	{
		if (!ft_died_check(arg))
			return (NULL);
		ft_eating(arg, start, id);
		ft_sleeping(arg, start, id);
		ft_thinking(arg, start, id);
	}
	pthread_mutex_lock(&arg->finish_mutex);
	arg->finish = 1;
	pthread_mutex_unlock(&arg->finish_mutex);
	return (NULL);
}
