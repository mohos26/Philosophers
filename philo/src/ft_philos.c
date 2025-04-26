/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:53:01 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/26 20:05:53 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// left = id - 1;
// rigth = (id) % arg->number_philo;

static void	ft_eating(t_all *arg, int id, long start)
{
	pthread_mutex_lock(&arg->forks[id % arg->number_philo]);
	printf("%ld %d has taken a fork\n", ft_get_time() - start, id);
	pthread_mutex_lock(&arg->forks[id - 1]);
	printf("%ld %d has taken a fork\n", ft_get_time() - start, id);
	printf("%ld %d is eating\n", ft_get_time() - start, id);
	pthread_mutex_lock(&arg->meal_mutex);
	arg->last_meal[id - 1] = ft_get_time();
	pthread_mutex_unlock(&arg->meal_mutex);
	usleep(arg->time_eat * 1000);
	pthread_mutex_unlock(&arg->forks[id - 1]);
	pthread_mutex_unlock(&arg->forks[id % arg->number_philo]);
}

void	*ft_philos(void *n)
{
	long	start;
	t_all	*arg;
	int		id;
	int		i;

	arg = ft_get_arg(NULL);
	id = *(int *)n + 1;
	i = 0;
	start = ft_start(1);
	if (!(id % 2))
		usleep(1000);
	while (i++ != arg->number_philo_must_eat)
	{
		ft_eating(arg, id, start);
		printf("%ld %d is sleeping\n", ft_get_time() - start, id);
		usleep(arg->time_sleep * 1000);
		printf("%ld %d is thinking\n", ft_get_time() - start, id);
	}
	// if (id == 1)
	// 	pthread_detach(*arg->monitor);
	return (NULL);
}
