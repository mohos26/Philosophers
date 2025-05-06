/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:41:03 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 10:53:48 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_all	*ft_get_info(char **av)
{
	t_all	*arg;

	arg = malloc(sizeof(t_all));
	if (!arg)
		return (free(arg), NULL);
	arg->number_philo = ft_atoi(av[0]);
	if (arg->number_philo < 1 || arg->number_philo > 200)
		return (free(arg), NULL);
	arg->time_die = ft_atoi(av[1]);
	if (arg->time_die == -1)
		return (free(arg), NULL);
	arg->time_eat = ft_atoi(av[2]);
	if (arg->time_eat == -1)
		return (free(arg), NULL);
	arg->time_sleep = ft_atoi(av[3]);
	if (arg->time_sleep == -1)
		return (free(arg), NULL);
	arg->number_philo_must_eat = ft_atoi(av[4]);
	if (arg->number_philo_must_eat == -1 && av[4])
		return (free(arg), NULL);
	arg->finish = 0;
	arg->died_flag = 0;
	return (arg);
}
