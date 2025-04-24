/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosopher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:17:21 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/24 18:58:40 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_guarded_fork_pick(int id_fork, long start, int id)
{
	long	now;

	pthread_mutex_lock(ft_forks(id_fork));
	now = ft_get_time();
	if (now - start >= ft_get_info(NULL, 2))
	{
		printf("%ld %d died\n", now - ft_start(1), id);
		exit(1);
	}
}

static void	ft_print(int id, int flag)
{
	const char	*s;

	s = NULL;
	if (flag == 1)
		s = "is thinking";
	else if (flag == 2)
		s = "has taken a fork";
	else if (flag == 3)
		s = "is eating";
	else if (flag == 4)
		s = "is sleeping";
	printf("%ld %d %s\n", ft_get_time() - ft_start(1), id + 1, s);
}

static void	ft_take_forks(int id, int rigth, int left, long start)
{
	if (rigth == left)
	{
		printf("%d %d died\n", ft_get_info(NULL, 2), id);
		exit(1);
	}
	if (id % 2)
	{
		ft_guarded_fork_pick(left, start, id);
		ft_print(id, 2);
		ft_guarded_fork_pick(rigth, start, id);
		ft_print(id, 2);
	}
	else
	{
		ft_guarded_fork_pick(rigth, start, id);
		ft_print(id, 2);
		ft_guarded_fork_pick(left, start, id);
		ft_print(id, 2);
	}
}

void	*ft_philosopher(void *n)
{
	int		i;
	int		id;
	int		left;
	int		rigth;
	long	start;

	i = 0;
	id = *(int *)n;
	left = id;
	rigth = (id + 1) % ft_get_info(NULL, 1);
	start = ft_get_time();
	pthread_mutex_lock(ft_meal_lock(id));
	ft_last_meal(id, start, 1);
	pthread_mutex_unlock(ft_meal_lock(id));
	while (ft_get_info(NULL, 5) == -1 || i < ft_get_info(NULL, 5))
	{
		ft_print(id, 1);
		ft_take_forks(id, rigth, left, start);
		ft_print(id, 3);
		usleep(ft_get_info(NULL, 3) * 1000);
		pthread_mutex_unlock(ft_forks(rigth));
		pthread_mutex_unlock(ft_forks(left));
		start = ft_get_time();
		pthread_mutex_lock(ft_meal_lock(id));
		ft_last_meal(id, start, 1);
		pthread_mutex_unlock(ft_meal_lock(id));
		ft_print(id, 4);
		usleep(ft_get_info(NULL, 4) * 1000);
		i++;
	}
	return (NULL);
}
