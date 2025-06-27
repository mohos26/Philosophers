/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:43:57 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/24 17:15:28 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_check_death(t_all *arg, int id)
{
	int		i;
	long	now;

	now = ft_get_time();
	if (!arg->is_eating[id] && now - arg->last_meal[id] >= arg->time_die)
	{
		pthread_mutex_lock(&arg->print_mutex);
		arg->died_flag = 1;
		pthread_mutex_unlock(&arg->print_mutex);
		i = 0;
		while (i < arg->number_philo)
			pthread_detach(arg->philos[i++]);
		pthread_mutex_lock(&arg->print_mutex);
		printf("%ld %d died\n", now - ft_start(1), id + 1);
		i = 0;
		while (i < arg->number_philo)
			pthread_join(arg->philos[i++], NULL);
		pthread_mutex_unlock(&arg->print_mutex);
		return (0);
	}
	return (1);
}

void	*ft_monitor(void *data)
{
	t_all	*arg;
	int		flag;
	int		i;

	flag = 1;
	arg = (t_all *)data;
	while (flag && ft_finsh_check(arg))
	{
		i = 0;
		while (flag && i < arg->number_philo)
		{
			if (!ft_finsh_check(arg))
				return (NULL);
			pthread_mutex_lock(&arg->meal_mutex);
			flag = ft_check_death(arg, i);
			pthread_mutex_unlock(&arg->meal_mutex);
			i++;
		}
		usleep(100);
	}
	return (NULL);
}
