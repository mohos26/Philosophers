/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finsh_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoussas <mhoussas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 07:20:43 by mhoussas          #+#    #+#             */
/*   Updated: 2025/05/06 08:11:28 by mhoussas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_finsh_check(t_all *arg)
{
	pthread_mutex_lock(&arg->finish_mutex);
	if (arg->finish)
	{
		pthread_mutex_unlock(&arg->finish_mutex);
		return (0);
	}
	pthread_mutex_unlock(&arg->finish_mutex);
	return (1);
}
