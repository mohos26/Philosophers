/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:26:31 by mhoussas          #+#    #+#             */
/*   Updated: 2025/04/23 19:11:05 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int ac, char **av)
{
	pthread_t	philos[200];
	int			ids[200];
	int			i;

	if (!(ac == 5 || ac == 6))
		return (ft_putendl_fd("!!! Invalide Number Of Arguments !!!", 2), 1);
	if (ft_get_info(av + 1, 0))
		return (ft_putendl_fd("!!! Invalide Arguments !!!", 2), 1);
	ft_forks(-1);
	i = 0;
	ft_start(0);
	while (i < ft_get_info(NULL, 1))
	{
		ids[i] = i;
		pthread_create(&philos[i], NULL, ft_philosopher, &ids[i]);
		i++;
	}
	i = 0;
	while (i < ft_get_info(NULL, 1))
		pthread_join(philos[i++], NULL);
	i = 0;
	while (i < ft_get_info(NULL, 1))
		pthread_mutex_destroy(ft_forks(i++));
	return (0);
}
