/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:43:57 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/29 15:32:33 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	ft_aid(t_all *arg, int id)
{
	long	now;
	int		i;

	now = ft_get_time();
	if (now - arg->last_meal[id] >= arg->time_die)
	{
		i = 0;
		while (i < arg->number_philo)
			pthread_detach(arg->philos[i++]);
		printf("%ld %d died\n", now - ft_start(1), id + 1);
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
	while (flag)
	{
		i = 0;
		while (flag && i < arg->number_philo)
		{
			pthread_mutex_lock(&arg->meal_mutex);
			flag = ft_aid(arg, i);
			pthread_mutex_unlock(&arg->meal_mutex);
			i++;
		}
	}
	return (NULL);
}
