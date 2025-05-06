/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:31:36 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 09:03:13 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static pthread_mutex_t	*ft_init_forks(t_all *arg)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * (arg->number_philo + 1));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < arg->number_philo)
		pthread_mutex_init(&forks[i++], NULL);
	return (forks);
}

static void	ft_aid(t_all *arg)
{
	pthread_t	monitor;
	int			ids[200];
	int			i;

	i = 0;
	pthread_create(&monitor, NULL, ft_monitor, (void *)arg);
	while (i < arg->number_philo)
	{
		ids[i] = i;
		pthread_create(&arg->philos[i], NULL, ft_philos, &ids[i]);
		i++;
	}
	i = 0;
	arg->monitor = &monitor;
	pthread_join(monitor, NULL);
	while (i < arg->number_philo)
		pthread_join(arg->philos[i++], NULL);
	pthread_detach(monitor);
	i = 0;
	while (i < arg->number_philo)
		pthread_mutex_destroy(&arg->forks[i++]);
	pthread_mutex_destroy(&arg->meal_mutex);
	pthread_mutex_destroy(&arg->finish_mutex);
	pthread_mutex_destroy(&arg->print_mutex);
}

int	main(int ac, char **av)
{
	t_all		*arg;
	int			i;

	if (!(ac == 5 || ac == 6))
		return (ft_putendl_fd("!!! Invalide Number Of Arguments !!!", 2), 1);
	arg = ft_get_info(av + 1);
	if (!arg)
		return (ft_putstr_fd("Error\n", 2), 1);
	pthread_mutex_init(&arg->meal_mutex, NULL);
	arg->forks = ft_init_forks(arg);
	if (!arg->forks)
		return (ft_putstr_fd("Error\n", 2), 1);
	pthread_mutex_init(&arg->finish_mutex, NULL);
	pthread_mutex_init(&arg->print_mutex, NULL);
	ft_get_arg(arg);
	arg->philos = malloc(sizeof(pthread_t) * (arg->number_philo + 1));
	if (!arg->philos)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_start(0);
	i = 0;
	while (i < arg->number_philo)
		arg->last_meal[i++] = ft_start(1);
	ft_aid(arg);
	return (0);
}
