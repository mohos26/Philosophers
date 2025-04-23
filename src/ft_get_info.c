/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:08:02 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/23 17:51:38 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_aid(char *s)
{
	static int	flag;
	int			n;

	if (!s)
		return (flag);
	n = ft_atoi(s);
	if (n == -1)
		flag = 1;
	return (n);
}

int	ft_get_info(char **av, int i)
{
	static int	number_of_philosophers;
	static int	time_to_die;
	static int	time_to_eat;
	static int	time_to_sleep;
	static int	number_of_times_each_philosopher_must_eat;

	if (av)
	{
		number_of_philosophers = ft_aid(av[0]);
		time_to_die = ft_aid(av[1]);
		time_to_eat = ft_aid(av[2]);
		time_to_sleep = ft_aid(av[3]);
		number_of_times_each_philosopher_must_eat = -1;
		if (av[4])
			number_of_times_each_philosopher_must_eat = ft_aid(av[4]);
	}
	else if (i == 1 || i == 2)
		return (number_of_philosophers * (i == 1) + time_to_die * (i == 2));
	else if (i == 3)
		return (time_to_eat);
	else if (i == 4)
		return (time_to_sleep);
	else if (i == 5)
		return (number_of_times_each_philosopher_must_eat);
	return (ft_aid(NULL));
}
