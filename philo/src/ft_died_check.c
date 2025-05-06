/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_died_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 08:18:03 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 08:39:11 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_died_check(t_all *arg)
{
	pthread_mutex_lock(&arg->print_mutex);
	if (arg->died_flag)
	{
		pthread_mutex_unlock(&arg->print_mutex);
		return (0);
	}
	pthread_mutex_unlock(&arg->print_mutex);
	return (1);
}
