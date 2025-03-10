/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:08:02 by mhoussas          #+#    #+#             */
/*   Updated: 2025/03/10 14:44:33 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philosophers	*ft_init_philos(char **av)
{
	t_philosophers	*philos;

	philos = ft_malloc(sizeof(t_philosophers));
	philos->number_of_philosophers = ft_atoi(av[0]);
	philos->time_to_die = ft_atoi(av[1]);
	philos->time_to_eat = ft_atoi(av[2]);
	philos->time_to_sleep = ft_atoi(av[3]);
	if (av[4])
		philos->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	else
		philos->number_of_times_each_philosopher_must_eat = -1;
	return (philos);
}
