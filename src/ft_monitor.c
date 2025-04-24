/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:43:15 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/24 19:00:55 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_last_meal(int id, int n, int flag)
{
	static long	last_meal_time[200];

	if (flag)
		last_meal_time[id] = n;
	return (last_meal_time[id]);
}

pthread_mutex_t	*ft_meal_lock(int id)
{
	static pthread_mutex_t	meal_lock[200];
	int						i;

	if (id == -1)
	{
		i = 0;
		while (i < ft_get_info(NULL, 1))
			pthread_mutex_init(&meal_lock[i++], NULL);
	}
	return (meal_lock);
}

void	*ft_monitor(void *arg)
{
	int	time_die;
	int	number_philos;

	time_die = ft_get_info(NULL, 2);
	number_philos = ft_get_info(NULL, 1);
	while (1 || arg)
	{
		for (int id = 0; id < number_philos; id++)
		{
			pthread_mutex_lock(ft_meal_lock(id));
			long diff = ft_get_time() - ft_last_meal(id, 0, 0);
			pthread_mutex_unlock(ft_meal_lock(id));
			if (diff >= time_die)
			{
				printf("Monitor: Philosopher %d died. Time without forks: %ld sec\n", id, diff);
				exit(1);
			}
		}
		usleep(100000);
	}
	return (NULL);
}
