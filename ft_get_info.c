/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:08:02 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/21 16:04:04 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_get_info(char **av, int i)
{
	static int	number_of_philosophers;
	static int	time_to_die;
	static int	time_to_eat;
	static int	time_to_sleep;
	static int	number_of_times_each_philosopher_must_eat;

	if (av)
	{
		number_of_philosophers = ft_atoi(av[0]);
		time_to_die = ft_atoi(av[1]);
		time_to_eat = ft_atoi(av[2]);
		time_to_sleep = ft_atoi(av[3]);
		if (av[4])
			number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
		else
			number_of_times_each_philosopher_must_eat = -1;
		return (0);
	}
	if (i == 1)
		return (number_of_philosophers);
	else if (i == 2)
		return (time_to_die);
	else if (i == 3)
		return (time_to_eat);
	else if (i == 4)
		return (time_to_sleep);
	else if (i == 5)
		return (number_of_times_each_philosopher_must_eat);
	return (0);
}
